#include "threadmonster.h"
#include <QDebug>
#include "Language.h"

ThreadMonster::ThreadMonster( const QSet<QString>& words, const QMap<QString, QString>& slovar, QWidget* parent )
    : QThread( parent ), words( words ), slovar( slovar )
{

}

void ThreadMonster::run()
{
    RecordList record_list;
    for( const auto& word : words )
    {
        if ( word.size() > 3 )
        {
            QSet<QString> str_list;
            for( int i = 0; i < word.size(); ++i )
            {
                QString str = word.toLower();
                for( const auto& letter : ALPHABETS[Language::Russian] )
                {
                    str[i] = letter;
                    if ( slovar.end() != slovar.find( str ) )
                    {
                        str_list.insert( str );
                    }
                }
            }
            //qDebug() << word << " " << str_list.size();

            if ( str_list.size() )
                record_list.push_back( { word, str_list } );
        }
    }
    emit VSE( record_list );
    deleteLater();
}
