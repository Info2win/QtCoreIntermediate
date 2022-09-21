#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess process;
    process.start("C:/Users/ilker/AppData/Local/Programs/MarkText/MarkText.exe");
    QTimer::singleShot(3000,&process,&QProcess::terminate);

    return a.exec();
}
