#ifndef THREADMONSTER_H
#define THREADMONSTER_H

#include <QThread>
#include <QWidget>
#include <QMetaType>
#include <QMap>
#include <QSet>

struct Record{
    QString word;
    QSet<QString> result;
};

using RecordList = QVector<Record>;

class ThreadMonster : public QThread
{
    Q_OBJECT
public:
    ThreadMonster( const QSet<QString>& words, const QMap<QString, QString>& slovar, int size_word, QWidget* parent = nullptr );

    void run() override;

signals:
    void VSE( RecordList );

private:
    QSet<QString> words;
    QMap<QString, QString> slovar;
    int size_word;
};

#endif // THREADMONSTER_H
