#include <QCoreApplication>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>

void list (QDir& root)
{
    qInfo() << "---Listing---";
    foreach(QFileInfo fileInfo, root.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Name)) // take all the entries without repeating itself or its parent then order them according to their names
    {
        if(fileInfo.isFile()) qInfo() << "File: " << fileInfo.filePath();
        if(fileInfo.isDir())
        {
             qInfo() << "Dir: "<< fileInfo.filePath();
             QDir child (fileInfo.filePath());
             qInfo() << "Inspecting: " << child.absolutePath();
             list(child);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir (a.applicationDirPath());
    dir.cdUp();
    list(dir);


    return a.exec();
}
