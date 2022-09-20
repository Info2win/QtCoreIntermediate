#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QRandomGenerator>

void random(QList<int> *list, int max)
{
    list->reserve(max);
    for(int i=0; i<max; i++)
    {
        list->append(QRandomGenerator::global()->bounded(1000));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    random(&list,10);
    qInfo() << "Unsorted" << list;
    std::reverse(list.begin(),list.end());
    qInfo() << "Reverse" << list;
    std::sort(list.begin(),list.end());
    qInfo() << "Sorted" << list;

    return a.exec();
}
