#include "threadprognoz.h"

ThreadPrognoz::ThreadPrognoz( const std::function<RecordMap()> func, QWidget* parent )
    : QThread( parent ), calc( func )
{

}

void ThreadPrognoz::run()
{
     auto result = calc();
     emit END( result );
     deleteLater();
}
