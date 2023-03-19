#include "encryption.h"
#include <QRandomGenerator>

Encryption::Encryption( Language lang )
    : language( lang )
{

}

QMap<QChar, QChar> Encryption::NewGenerateAlph()
{
    QRandomGenerator rand;
    QMap<QChar, QChar> alph;
    for ( const auto& next_ch : ALPHABETS[language] )
    {
        QChar ch = ALPHABETS[language][qrand() % ALPHABETS[language].size()];
        while ( alph.contains( ch ) || next_ch == ch )
        {
            ch = ALPHABETS[language][qrand() % ALPHABETS[language].size()];
        }
        alph.insert( ch, next_ch );
    }
    return alph;
}

void Encryption::EncryptText( QString &text )
{
    auto alph = NewGenerateAlph();

    for ( const auto& key : alph.keys() )
    {
        log += key;
        log += " - ";
        log += alph[key];
        log += "\n";
    }

    for( auto& symbol : text )
    {
        auto it  = alph.find( symbol );
        if ( alph.end() != it )
        {
            symbol = it.value();
            continue;
        }
        QChar ch = QChar( symbol.toLower().unicode() );
        it  = alph.find( ch );
        if ( alph.end() != it )
        {
            symbol = it.value().toUpper();
            continue;
        }
    }
}

QString Encryption::GetLog(){
    return log;
}

void Encryption::SetLang( Language lang )
{
    language = lang;
}

Language Encryption::GetLang()
{
    return language;
}
