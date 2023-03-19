#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class Form;
}

class Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void setText( const QString& text );
    void restartText( const QString& text );

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    QString textOnEncrypt;
    QMap<QChar, QChar> rules; // шифр / отгадка
};

#endif // FORM_H
