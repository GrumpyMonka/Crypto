#include "form.h"
#include "ui_form.h"
#include "Language.h"

Form::Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setAttribute( Qt::WA_DeleteOnClose );

    int start_alph = ALPHABETS[Language::Russian][0].unicode();
    int end_alph = ALPHABETS[Language::Russian][1].unicode();
    for ( auto i = start_alph; i <= end_alph; i++ )
    {
        rules.insert( QChar( i ), QChar( i ) );
    }
}

Form::~Form()
{
    delete ui;
}

void Form::setText( const QString& text )
{
    textOnEncrypt = text;
    ui->textEdit->setText( text );
}

void Form::on_pushButton_clicked()
{
    QString start = ui->lineEdit_2->text();
    QString end = ui->lineEdit->text();

    if ( start.size() != end.size() )
    {
        return;
    }

    for ( int i = 0; i < start.size(); ++i )
    {
        auto start_it = rules.find( rules.key( start[i] ) );
        auto end_it = rules.find( rules.key( end[i] ) );
        if ( rules.end() != start_it && rules.end() != end_it )
        {
            rules.find( rules.key( start[i] ) ).value() = end[i];
            rules.find( rules.key( end[i] ) ).value() = start[i];
        }
    }
}

void Form::restartText( const QString& text )
{
    ui->textEdit->clear();
    for( const auto& simbol : text )
    {
        auto it = rules.find( simbol );
        if ( rules.end() != it )
        {
            ui->textEdit->insertPlainText( it.value() );
        }
        ui->textEdit->insertPlainText( simbol );
    }
}
