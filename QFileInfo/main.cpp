#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QString path)
{
        qInfo() << "List: " << path;

        QDir dir(path);
        QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
        QFileInfoList files = dir.entryInfoList(QDir::Files);

        foreach(QFileInfo fileInfo, dirs)
        {
            qInfo()<< fileInfo.fileName();

        }
        foreach(QFileInfo fileInfo, files)
        {
            qInfo()<< "Name: " <<fileInfo.fileName();
            qInfo()<< "Size: " <<fileInfo.size();
            qInfo()<< "Created: " <<fileInfo.birthTime();
            qInfo()<< "Modified: " <<fileInfo.lastModified();
        }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    list(QDir::tempPath());
    qInfo() << "Done"; // even do there are some locked directories program terminates without crashing
    return a.exec();
}
