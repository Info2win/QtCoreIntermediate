#include <QCoreApplication>
#include <QScopedPointer>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThread worker;
    worker.setObjectName("Worker Thread");
    qInfo()<< "Starting work" << QThread::currentThread();
    QScopedPointer<Task> t (new Task());
    Task *task = t.data();
    task->moveToThread(&worker);
    worker.connect(&worker,&QThread::started,task,&Task::work);
    worker.start();
    qInfo() << "Free to do what do you want..." << QThread::currentThread();
    return a.exec();
}
