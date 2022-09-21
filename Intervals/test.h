#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Test : public QObject
{
    Q_OBJECT
private:
    QTimer timer;
    int number;
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void dostuff();
    void timeout();



};

#endif // TEST_H
