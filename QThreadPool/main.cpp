#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting work" << QThread::currentThread();
    qInfo()<< "Max Threads" << QThreadPool::globalInstance()->maxThreadCount();

    for(int i=0; i<50; i++)
    {
        Task *task = new Task();
        task->setAutoDelete(true);
        QThreadPool::globalInstance()->start(task);
    }


    return a.exec();
}
