#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;

    if(buffer.open(QIODevice::ReadWrite))
    {
        qInfo()<< "Device is open";
        QByteArray data("Hello world");
        for(int i=0; i<5;i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }
        // buffer.flush(); - no need to flush for this device
        buffer.seek(0); // readAll reads from where the curser is to the end so we need to seek to the begning to read all of the file
        qInfo()<< buffer.readAll();
        qInfo() << "Closing buffer";
        buffer.close();
    }
    else
    {
     qInfo() << "Could not open the device";
    }
    qInfo()<< "Finished";
    return a.exec();
}
