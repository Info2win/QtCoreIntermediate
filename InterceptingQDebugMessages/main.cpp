#include <QCoreApplication>
#include <QTextStream>
#include <QDateTime>
#include <QFile>

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

void lhandler(QtMsgType type,const QMessageLogContext& context, const QString& msg)
{
    QString log;
    switch (type) {
    case QtInfoMsg:
        log = QString("Info: %1").arg(msg);
        break;
    case QtDebugMsg:
        log = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        log = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        log = QString("Critical %1").arg(msg);
        break;
    case QtFatalMsg:
        log = QString("Fatal: %1").arg(msg);
        break;
    }
    QFile file("log.txt");
    if(file.open(QIODevice::Append))
    {
        QTextStream stream(&file);
        stream << QDateTime::currentDateTime().toString() << "-" << "file: " << context.file << "line: " << context.line << "\r\n";
        file.close();
    }
    (*QT_DEFAULT_MESSAGE_HANDLER)(type,context,msg);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInstallMessageHandler(lhandler);

    qInfo() << "This is a info message";
    qDebug() << "This is a debug message";
    qWarning() << "This is a warning message";
    qCritical() << "This is a critical message";
    qFatal("THIS IS FATAL!!!");

    return a.exec();
}
