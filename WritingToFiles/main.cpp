#include <QCoreApplication>
#include <QFile>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; // this will put the file in the current directory of the app
    QFile file (filename);

    if(file.open(QIODevice::WriteOnly))
    {
        QString now = QDateTime::currentDateTime().toString();
        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(" - Hello World");
        file.write(data); // this function overwrites the data
        file.close();
        qInfo()<< "Wrote to the file";
    }
    else
    {
        qInfo()<< file.errorString();
    }

    return a.exec();
}
