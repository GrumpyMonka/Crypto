#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>
#include <QMap>

enum Language
{
    Russian,
    English
};

const QMap<Language, QString> ALPHABETS
{
    { Language::Russian, "абвгдеёжзийклмнопрстуфхцчшщъыьэюя" },
    { Language::English, "abcdefghijklmnopqrstuvwxyz" }
};

const QMap<Language, QString> LANGUAGE
{
    { Language::Russian, "Russian" },
    { Language::English, "English" }
};

#endif // LANGUAGE_H
