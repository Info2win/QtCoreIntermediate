#include <QCoreApplication>

void display(QString title, QByteArray& bytes)
{
    qDebug() << "---" << title << "---";
    qDebug() << "Length: " << bytes.size();
    qDebug() << "Plain:" << bytes;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data ("I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data,I am an annoyingly long data");

    QByteArray compressed = qCompress(data,9);
    QByteArray decompressed = qUncompress(compressed);

    display("Original data: ",data);
    display("Compressed data: ",compressed);
    display("Decompressed data: ",decompressed);
    return a.exec();
}
