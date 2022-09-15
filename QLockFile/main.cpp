#include <QCoreApplication>
#include <QLockFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Attempting to lock a file...";

    QString path =  QDir::currentPath() +QDir::separator() +"test.txt";
    QFile file(path);
    QLockFile lockFile(file.fileName()+"l");
    lockFile.setStaleLockTime(15000);
    if(lockFile.tryLock())
    {
        qInfo() << "Putting into file...";
        if(file.open(QIODevice::WriteOnly))
        {
            QByteArray data;
            data.append("Hello World ");
            file.write(data);
            file.close();
        }
        else qWarning() << file.errorString();

//        qInfo() << "Unlucking file...";
//       lockFile.unlock(); // Comment out to see it lock
    }
    else
    {
        qInfo() << "Could not lock the file!";
        qint64 pid;
        QString host;
        QString application;

        if(lockFile.getLockInfo(&pid,&host,&application))
        {
            qInfo() << "The file is locked by: ";
            qInfo()<< "Pid: " << pid;
            qInfo() << "Host: " << host;
            qInfo() << "Application: " << application;
        }
        else
        {
            qWarning() << "File is locked, but we could not get the info!";
        }
    }



    return a.exec();
}
