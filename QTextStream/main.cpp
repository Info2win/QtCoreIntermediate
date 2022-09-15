#include <QCoreApplication>
#include <QTextStream>
#include <QFile>

void writeFile(QFile& file)
{
    if(!file.isWritable())
    {
        qWarning() << "File is not writable!";
        return;
    }
    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::LastEncoding); // we do not really have to have this line as default encoding is LastEncoding but we would set encoding to something else such as UTF-16 or UTF-32
    stream.seek(file.size());
    for(int i=0; i<5 ; i++)
    {
        stream << QString::number(i)<<"-Item\r\n";
    }
    stream.flush();
    qInfo() << "Wrote to file";
}

void readFile(QFile& file)
{
    if(!file.isReadable())
    {
        qWarning() << "File is not readable!";
        return;
    }
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.readLine();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt";

    QFile file(filename);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        qInfo() << "Encoding:" << stream.encoding();
        writeFile(file);
        readFile(file);
        file.close();
    }
    else
    {
        qWarning() << file.errorString();
    }

    return a.exec();
}
