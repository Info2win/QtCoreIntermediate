#include <QCoreApplication>
#include <QTimer>

void test()
{
    qInfo()<< "Thank you for waiting";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<< "Please wait...";

    QTimer::singleShot(3000,&test);

    return a.exec();
}
