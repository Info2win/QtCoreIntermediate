#include <QCoreApplication>
#include <QFile>
#include <QVariant>
#include <QVariantMap>
#include "test.h"
#include "converter.h"

void writexml(QString path)
{
    Test t;
    t.fill();
    Converter::writeXML(&t,path);
}

void readxml(QString path)
{
    Test *t;
    t = Converter::readXML(t,path);
    if(!t)
    {
        qInfo()<< "Object not loaded!";
        return;
    }
    qInfo()<< "Name: "<< t->name();
    foreach(QString key, t->map().keys())
    {
        qInfo() << key << " : " << t->map().value(key);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    writexml(path);
    readxml(path);

    return a.exec();
}
