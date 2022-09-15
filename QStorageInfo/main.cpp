#include <QCoreApplication>
#include <QStorageInfo>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStorageInfo root = QStorageInfo::root(); // root of the operating system
    qInfo() << "Root: " << root.rootPath();
    QDir dir(root.rootPath());
    foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        qInfo() << fileInfo.filePath();
    }
    qInfo()<< "-------------------------";

    foreach(QStorageInfo storage, QStorageInfo::mountedVolumes())
    {
        qInfo()<<"Name: "<<storage.displayName();
        qInfo()<<"Type: "<<storage.fileSystemType();
        qInfo()<<"Total: "<<storage.bytesTotal()/1000/1000 << "MB";
        qInfo()<<"Avaiable bytes"<< storage.bytesAvailable()/1000/1000 << "MB";
        qInfo()<<"Device: "<<storage.device();
        qInfo()<<"Root: "<<storage.isRoot();
    }
    qInfo()<< "Done!";
    return a.exec();
}
