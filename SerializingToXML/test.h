#ifndef TEST_H
#define TEST_H

#include "qdebug.h"
#include <QObject>

class Test : public QObject
{
    Q_OBJECT
private:
    QString m_name;
    QMap<QString, QString> m_map;
public:
    explicit Test(QObject *parent = nullptr);
    void fill();
    QString name();
    void setName(QString value);
    QMap<QString,QString> map();
    void setMap(QMap<QString, QString> newMap);

    friend QDataStream& operator << (QDataStream &stream,const Test &t)
    {
        qInfo() << "Operator <<";
        stream << t.m_name << t.m_map;

        return stream;
    }
    friend QDataStream& operator >> (QDataStream &stream, Test &t)
    {
        qInfo() << "Operator >>";
        stream >> t.m_name >> t.m_map;

        return stream;
    }

signals:

};

#endif // TEST_H

