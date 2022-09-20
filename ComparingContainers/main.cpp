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

    QList<int> list1,list2;
    random(&list1,10);
    random(&list2,10);
    qInfo() << "List 1 : " << list1;
    qInfo() << "List 2 : " << list2;
    qInfo() << "Equal? " << std::equal(list1.begin(),list1.end(),list2.begin());
    list1.fill(5);
    list2.fill(5);
    qInfo() << "List 1 : " << list1;
    qInfo() << "List 2 : " << list2;
    qInfo() << "Equal? " << std::equal(list1.begin(),list1.end(),list2.begin());

    return a.exec();
}
