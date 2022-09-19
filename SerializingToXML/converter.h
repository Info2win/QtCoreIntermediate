#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include "test.h"
#include <QFile>
#include <QMap>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class Converter : public QObject
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = nullptr);
    static void writeXML(Test *obj,QString path);
    static Test* readXML(Test *obj,QString path);

signals:

};

#endif // CONVERTER_H
