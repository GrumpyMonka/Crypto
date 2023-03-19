#ifndef FORMENCRYPT_H
#define FORMENCRYPT_H

#include <QMainWindow>
#include <QMap>
#include "threadmonster.h"
#include "Language.h"

namespace Ui {
class FormEncrypt;
}

class FormEncrypt : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormEncrypt(QWidget *parent = nullptr);
    ~FormEncrypt();

public slots:
    QMap<QChar, QChar> LetterSub( const QMap<QChar, QChar> now_keys, const QString& start, const QString& end );
    QString SubLetterInText( const QString& text, const QMap<QChar, QChar>& now_keys );

    void setText( const QString& text );
    void searchWord();
    int checkWordOnTrue( const QString& text );
    void LoadFile();
    void WAIT( RecordList );
    void resetViewKey();
    void setDecryptKey( const QMap<QChar, QChar> map );

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormEncrypt *ui;
    QString textOnEncrypt;
    QString startText;
    int size_true_word;
    QMap<QString, QString> list_word;
    QMap<QChar, QChar> decrypt_key;

    QVector<QMap<QChar, QChar>> used_decrypt_key;

    struct Wait{
        int count;
        RecordList list;
    };

    Wait wait;
    int size_word = SIZE_WORD_MAX;
};

#endif // FORMENCRYPT_H
