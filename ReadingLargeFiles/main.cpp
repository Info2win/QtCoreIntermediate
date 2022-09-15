#include <QCoreApplication>
#include <QFile>

void readLines(QFile& file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
       qInfo() << file.readLine();
    }
}

void readChunks(QFile& file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.read(23);
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; // we have created this file manually

    QFile file(filename);
    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        readLines(file);
        qInfo()<< "--------------------------";
        readChunks(file);
        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }
    return a.exec();
}
