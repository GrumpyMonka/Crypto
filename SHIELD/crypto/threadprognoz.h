#ifndef THREADPROGNOZ_H
#define THREADPROGNOZ_H

#include "threadmonster.h"

using RecordMap = QPair<int, QMap<QChar, QChar>>;

class ThreadPrognoz : public QThread
{
    Q_OBJECT
public:
    ThreadPrognoz( const std::function<RecordMap()> func, QWidget* parent = nullptr );

    void run() override;

signals:
    void END( RecordMap );

private:
    std::function<RecordMap()> calc;
};

#endif // THREADPROGNOZ_H
