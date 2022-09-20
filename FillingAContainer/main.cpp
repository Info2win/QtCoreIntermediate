#include <QCoreApplication>
#include <QList>
#include <QtAlgorithms>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 1 << 2 << 3 << 4;
    qInfo() << list;

    list.fill(9);
    qInfo() << list;

    list.resize(12);
    qInfo()<< list;

    std::fill(list.begin(),list.end(),-1);
    qInfo()<<list;

    return a.exec();
}
