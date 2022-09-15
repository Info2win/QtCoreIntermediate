#include <QCoreApplication>
#include <QFile>
#include <QDataStream>

bool write(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << file.errorString();
        return false;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_2);

    int age = 21;
    QString name="ilker";
    double weight = 88.59;

    stream << age << name << weight;

    qInfo() << "File is written";

    file.close();
    return true;
}

void read(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
        return;
    }
    QDataStream stream(&file);

    if(stream.version()!= QDataStream::Qt_6_2)
    {
        qWarning() << "Data versions dismatch!";
        return;
    }
    int age;
    QString name;
    double weight=100.0; // we can initialize the variables that we are going to read
    stream >>  age >> name >> weight; // read in the same order we write
    qInfo()<< "File is read";
    qInfo()<< "Age: " << age ;
    qInfo() << "Name: " << name;
    qInfo() << "Weight: " << weight;
    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename="test.txt";
    if(write(filename)) read(filename);

    return a.exec();
}
