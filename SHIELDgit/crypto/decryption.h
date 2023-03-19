#ifndef DECRYPTION_H
#define DECRYPTION_H

#include "Language.h"
#include <QString>
#include <QMap>
#include <QFile>

class Decryption
{
public:
    Decryption( Language lang = Language::Russian );

    void DecryptText( QString& text );

    QMap<QChar, QChar> GetAlph();
    void SetLang( Language lang );
    Language GetLang();

private:
    QMap<QChar, quint64> CalculateWeight( QString& list );
    QVector<QChar> GetRatingChar( QMap<QChar, quint64> );
    void LoadFile();

    Language language;
    QMap<QChar, quint64> data_base_weights;
    QString data_base_words;
    QMap<QChar, QChar> alphabet;
};

#endif // DECRYPTION_H
