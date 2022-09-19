#include "converter.h"

Converter::Converter(QObject *parent)
    : QObject{parent}
{

}

void Converter::writeXML(Test *obj, QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Could not write file!";
        qCritical() << file.errorString();
        return;
    }

    QXmlStreamWriter stream(&file);

    stream.setAutoFormatting(true);

    stream.writeStartDocument();
    stream.writeStartElement("test");
    stream.writeAttribute("name",obj->name());
    stream.writeStartElement("items");

    foreach(QString key, obj->map().keys())
    {
        stream.writeStartElement("item");
        stream.writeAttribute("key",key);
        stream.writeAttribute("value",obj->map()[key]);
        stream.writeEndElement();
    }

    stream.writeEndElement();
    stream.writeEndElement();
    stream.writeEndDocument();
    file.close();

}

Test *Converter::readXML(Test *obj, QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Could not read file!";
        qCritical() << file.errorString();
        return nullptr;
    }
    QByteArray data = file.readAll();
    file.close();

    QXmlStreamReader stream(data);
    Test *t = new Test();
    QMap<QString,QString> map;

    while(!stream.atEnd())
    {
        QXmlStreamReader::TokenType token = stream.readNext();
        switch (token) {
        case QXmlStreamReader::EndDocument:
            t->setMap(map);
        case QXmlStreamReader::StartElement:
            if(stream.name().toString() == "test")
            {
                QString name = stream.attributes().value("name").toString();
                t->setName(name);
            }
            else if(stream.name().toString()=="item")
            {
                QString key = stream.attributes().value("key").toString();
                QString value  =stream.attributes().value("value").toString();
                map.insert(key,value);
            }
        default:

            break;

        }

    }
    return t;
}
