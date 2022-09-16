#include <QCoreApplication>

QString makeData()
{
    QString data;

    for(int i=0; i<5; i++)
    {
        data.append("Hello\r\n");
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded" << encoded;
    qInfo("----------------------------");
    qInfo() << "Decoded: "<< decoded;

    return a.exec();
}
