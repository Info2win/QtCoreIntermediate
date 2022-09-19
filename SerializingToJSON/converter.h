#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include "test.h"
#include <QVariant>
#include <QFile>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMap>
class Converter : public QObject
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = nullptr);

    static void writeJson(Test *obj,QString path);
    static Test* readJson(QString path);

signals:

};

#endif // CONVERTER_H
