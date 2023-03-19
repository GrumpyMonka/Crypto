#include "formencrypt.h"
#include "ui_formencrypt.h"
#include "decryption.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>

FormEncrypt::FormEncrypt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormEncrypt)
{
    ui->setupUi(this);
    qRegisterMetaType<RecordList>("RecordList");
    setAttribute( Qt::WA_DeleteOnClose );
    LoadFile();
}

FormEncrypt::~FormEncrypt()
{
    delete ui;
}

void FormEncrypt::setText( const QString& text )
{
    textOnEncrypt = text;
    startText = text;

    Decryption decrypt( Language::Russian );
    decrypt.DecryptText( textOnEncrypt );
    setDecryptKey( decrypt.GetAlph() );
    textOnEncrypt = SubLetterInText( startText, decrypt_key );

    size_true_word = checkWordOnTrue( textOnEncrypt );
    resetViewKey();
    ui->textEdit->setText( textOnEncrypt );
    searchWord();
}

void FormEncrypt::on_pushButton_clicked()
{
    QString start = ui->lineEdit_2->text();
    QString end = ui->lineEdit->text();
    setDecryptKey( LetterSub( decrypt_key, start, end ) );
    textOnEncrypt = SubLetterInText( startText, decrypt_key );
    resetViewKey();
    ui->textEdit->setText( textOnEncrypt );
}

void FormEncrypt::resetViewKey()
{
    QStandardItemModel* model = new QStandardItemModel;//новая модель списка
    for ( const auto& key : decrypt_key.keys() )
        model->appendRow( new QStandardItem( QString( key ) + " - " + decrypt_key[key] ) );

    ui->listView_2->setModel( model );
}

QMap<QChar, QChar> FormEncrypt::LetterSub( const QMap<QChar, QChar> now_keys, const QString& start,  const QString& end )
{
    QString t_start = start.toLower();
    QString t_end = end.toLower();

    if ( t_start.size() != t_end.size() )
    {
        ui->statusbar->showMessage( "Строки не равны!" );
        return {};
    }

    QMap<QChar, QChar> used_char;
    for ( int i = 0; i < t_start.size(); ++i )
    {
        if ( -1 != ALPHABETS[Language::Russian].indexOf( t_start[i] ) && -1 != ALPHABETS[Language::Russian].indexOf( t_end[i] )
             && t_start[i] != t_end[i] && !( used_char.end() != used_char.find( t_end[i] ) && used_char[t_end[i]] == t_start[i] ) )
        {
            used_char[t_start[i]] = t_end[i];
        }
    }

    QMap<QChar, QChar> result = now_keys;
    for ( const auto& next_pair : used_char.keys() )
    {
        auto it_start = result.find( result.key( next_pair ) );
        auto it_end = result.find( result.key( used_char[next_pair] ) );
        it_start.value() = used_char[next_pair];
        it_end.value() = next_pair;
    }
    return result;
}

QString FormEncrypt::SubLetterInText( const QString& text, const QMap<QChar, QChar>& now_keys )
{
    QString result_text = text;
    for ( auto& ch : result_text )
    {
        bool flag = false;
        if ( ch.isUpper() )
        {
            flag = true;
            ch = ch.toLower();
        }

        if ( -1 != ALPHABETS[Language::Russian].indexOf( ch ) )
        {
            auto it = now_keys.find( ch );
            if ( now_keys.end() != it )
            {
                ch = it.value();
            }
        }

        if ( flag )
            ch = ch.toUpper();
    }
    return result_text;
}

QSet<QString> splitString( const QString& str )
{
    QSet<QString> result;
    QString temp;

    for ( const auto& next_char : str )
    {
        if ( -1 != ALPHABETS[Language::Russian].indexOf( next_char.toLower() ) )
        {
            temp += next_char;
        }
        else
        {
            result.insert( temp );
            temp = "";
        }
    }
    return result;
}

void FormEncrypt::LoadFile()
{
    QString path = "Language/" + LANGUAGE[Language::Russian] + ".txt";
    QFile file( path );
    QString data_base_words;
    if ( file.open( QIODevice::ReadOnly ) )
    {
        data_base_words = file.readAll();
        QStringList list = data_base_words.split( "\n" );
        for ( const auto& next_word : list )
        {
            list_word[next_word].push_back( next_word );
        }
        qDebug() << "Read file: " << list_word.size();
    }
    else
    {
        qDebug() << "Failed open file: " + path;
    }
    file.close();
}

void FormEncrypt::searchWord()
{
    QSet<QString> list = splitString( textOnEncrypt );

    int step = list.size() / THREAD_COUNT;
    wait.count = THREAD_COUNT;
    wait.list.clear();
    for( int i = 0; i < THREAD_COUNT; ++i )
    {
        QSet<QString> temp;
        for ( auto it = list.begin() + step * i; it != list.begin() + step * ( i + 1 ); ++it )
        {
            temp.insert( *it );
        }
        ThreadMonster* thread = new ThreadMonster( temp, list_word, size_word, this );
        connect( thread, SIGNAL( VSE( RecordList ) ), this,  SLOT( WAIT( RecordList ) ) );
        thread->start();
    }
}

int FormEncrypt::checkWordOnTrue( const QString& text )
{
    QSet<QString> list = splitString( text );
    int storage_size = 0;
    for( const auto& word : list )
    {
        if ( word.size() >= size_word )
        {
            if ( list_word.end() != list_word.find( word ) )
            {
                ++storage_size;
            }
        }
    }
    return storage_size;
}

void FormEncrypt::setDecryptKey( const QMap<QChar, QChar> map )
{
    decrypt_key = map;
    used_decrypt_key.push_back( map );
}

void FormEncrypt::WAIT( RecordList list )
{
    wait.count--;
    wait.list += list;
    if ( !wait.count ){
        qDebug() << "OK " << wait.list.size();

        bool flag = false;
        for( const auto& rec_list : wait.list )
        {
            for ( const auto& word : rec_list.result )
            {
                auto new_keys = LetterSub( decrypt_key, rec_list.word, word );
                if ( !new_keys.empty() )
                {
                    int count = checkWordOnTrue( SubLetterInText( startText, new_keys ) );
                    if ( count >= size_true_word && -1 == used_decrypt_key.indexOf( new_keys ) )
                    {
                        size_true_word = count;
                        setDecryptKey( new_keys );
                        flag = true;
                    }
                }
            }
        }

        if ( !flag )
        {
            size_word--;
                qDebug() << "size_word << " << size_word;

            if ( size_word >= SIZE_WORD_MIN )
            {
                searchWord();
            }
            else
            {
                ui->statusbar->showMessage( "END" );
            }
        }
        else
        {
            searchWord();
        }
        textOnEncrypt = SubLetterInText( startText, decrypt_key );
        ui->textEdit->setText( textOnEncrypt );
        resetViewKey();
        qDebug() << "size_true_word " << size_true_word;
    }
}


