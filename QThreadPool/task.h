#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QThread>
#include <QRunnable>
#include <QDebug>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();
signals:


    // QRunnable interface
public:
    void run();
};

#endif // TASK_H
