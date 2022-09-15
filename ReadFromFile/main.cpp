#include <QCoreApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt";
    QFile file(filename);
    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        qInfo()<<file.readAll();// this is safe for only small files
        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    return a.exec();
}
