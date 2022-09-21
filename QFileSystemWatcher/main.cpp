#include <QCoreApplication>
#include "watcher.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Watcher watcher;

    return a.exec();
}
