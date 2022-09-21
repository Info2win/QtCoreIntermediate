#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    number = 0;
    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,&Test::timeout);
}

void Test::timeout()
{
    number++;
    qInfo()<< QTime::currentTime().toString();
    if(number >= 5)
    {
        timer.stop();
        qInfo()<< "Complete!";
    }
}

void Test::dostuff()
{
    timer.start();
}
