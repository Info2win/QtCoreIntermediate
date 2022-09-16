#include "logger.h"

QString Logger::filename = QDir::currentPath() + QDir::separator() + "log.txt";
bool Logger::logging = false;
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger(QObject *parent)
    : QObject{parent}
{

}

void Logger::attach()
{
    Logger::logging = true;
    qInstallMessageHandler(Logger::handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    if(Logger::logging)
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
        QFile file(Logger::filename);
        if(file.open(QIODevice::Append))
        {
            QTextStream stream(&file);
            stream << QDateTime::currentDateTime().toString() << " - " << log  <<" File: "<< context.file << " Line: " << context.line << "\r\n";
            stream.flush();
        }

    }
     (*QT_DEFAULT_MESSAGE_HANDLER)(type,context,msg);
}
