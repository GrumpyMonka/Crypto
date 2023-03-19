#include "decryption.h"
#include <QDebug>

Decryption::Decryption( Language lang )
    : language( lang )
{
    //LoadFile();
    //data_base_weights = CalculateWeight( data_base_words );
}

QMap<QChar, quint64> Decryption::CalculateWeight( QString& list )
{
    QMap<QChar, quint64> score;
    for ( const auto& next_char : ALPHABETS[language] )
    {
        score.insert( next_char, 0 );
    }


    for ( const auto& symbol : list )
    {
        auto it = score.find( symbol.toLower() );
        if ( score.end() != it )
        {
            it.value()++;
        }
    }
    return score;
}

void Decryption::DecryptText( QString& text )
{
    auto weight = CalculateWeight( text );
    QVector<QChar> rating_text = GetRatingChar( weight );
    //QVector<QChar> rating_decryption = GetRatingChar( data_base_weights );
    QString rating_decryption = "оеаитнсрвлкмдпуяыгзбчйхъжьюшцщэфё";
    std::reverse( rating_decryption.begin(), rating_decryption.end() );

    QMap<QChar, QChar> crypt;
    int dis = rating_decryption.size() - rating_text.size();
    for ( int i = 0; i < rating_text.size(); i++ )
    {
        crypt.insert( rating_text[i], rating_decryption[i + dis] );
    }

    alphabet = crypt;
}

QMap<QChar, QChar> Decryption::GetAlph()
{
    return alphabet;
}

QVector<QChar> Decryption::GetRatingChar( QMap<QChar, quint64> weights )
{
    QVector<QPair<quint64, QChar>> result;
    for ( const auto& key : weights.keys() )
    {
        result.push_back( { weights[key], key } );
    }
    qSort( result );

    QVector<QChar> val;
    for ( int i = 0; i < result.size(); ++i )
    {
        val.push_back( result[i].second );
    }
    return val;
}

void Decryption::SetLang( Language lang )
{
    language = lang;
}

Language Decryption::GetLang()
{
    return language;
}

void Decryption::LoadFile()
{
    QString path = "Language/" + LANGUAGE[language] + ".txt";
    QFile file( path );
    if ( file.open( QIODevice::ReadOnly ) )
    {
        data_base_words = file.readAll();
    }
    else
    {
        qDebug() << "Failed open file: " + path;
    }
    file.close();
}
