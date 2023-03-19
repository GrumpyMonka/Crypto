#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QString>
#include <QMap>
#include "language.h"

class Encryption
{
public:
    Encryption( Language lang = Language::Russian );
    void EncryptText( QString& text );
    QString GetLog();
    void SetLang( Language lang );
    Language GetLang();

private:
    QMap<QChar, QChar> NewGenerateAlph();

private:
    Language language;
    QString log;
};

#endif // ENCRYPTION_H
