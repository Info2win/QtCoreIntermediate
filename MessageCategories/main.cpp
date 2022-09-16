#include <QCoreApplication>
#include <QLoggingCategory>

// Declare a logging category
Q_DECLARE_LOGGING_CATEGORY(network);

// Define the logging category
Q_LOGGING_CATEGORY(network,"Network");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "test";
    qWarning() << "test";

    qInfo(network) << "test";
    qWarning(network) << "test";

    // Turn the category off
    QLoggingCategory::setFilterRules("Network.debug=false");
    // Will not log
    qDebug(network) << "This will not log";

    if(!network().isDebugEnabled())
    {
        QLoggingCategory::setFilterRules("Network.debug=true");
        qDebug(network) << "Turned it back on!";
    }

    qDebug(network) << "Yes!";

    return a.exec();
}
