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

constexpr int SIZE_WORD_MAX = 4;
constexpr int SIZE_WORD_MIN = 2;
constexpr int THREAD_COUNT = 3;

#endif // LANGUAGE_H
