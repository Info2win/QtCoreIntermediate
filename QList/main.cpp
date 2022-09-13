#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;

    //Append
    list << 1 << 2 << 3 ;

    for(int i=0; i<5; i++)
    {
        list.append(i);
    }
    qInfo() << list;

    // Length , Size , Count

    qInfo() << "Length" << list.length();
    qInfo()<<"Size" << list.size();
    qInfo() << "Count" << list.count();
    qInfo()<< "Count of 4:" << list.count(4);

    // Replace, Remove, RemoveAll
    list.replace(2,99);
    list << 5 << 5 << 5;
    list.remove(5); // it only removes first occurance
    foreach(int i,list)
    {
        qInfo()<<i;
    }

    list.removeAll(5);

    for(int i=0; i<list.length();i++)
    {
        qInfo() << i << "-" << list.at(i);
    }
    //Slice
    QList<int> slice = list.sliced(2,3);

    qInfo() << "Slice" << slice;
    qInfo() << "List" << list;

    qInfo() << "Contains" << list.contains(6);
    qInfo()<< "IndexOf" << list.indexOf(6);
    // Clear
    list.clear();
    qInfo()<< "Length" << list.length();
    qInfo()<< "Size" << list.size();
    qInfo()<< "Count"<< list.count();
    return a.exec(); 
}
