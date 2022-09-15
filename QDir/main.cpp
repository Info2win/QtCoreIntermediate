#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QDir appDirectory)
{
    qInfo()<< "---Listing---";
    foreach(QFileInfo fileInfo, appDirectory.entryInfoList(QDir::Filter::Dirs,QDir::Name))
    {
        if(fileInfo.isDir()) qInfo()<< fileInfo.absoluteFilePath();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(a.applicationDirPath());
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();

    dir.cdUp();
    qInfo() << "cdUp(): "<< dir.absolutePath();
    list(dir);
    dir.mkdir("test");
    list(dir);
    dir.rmdir("test");
    list(dir);

    return a.exec();
}
