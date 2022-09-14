#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = QCoreApplication::applicationDirPath() + "/settings.ini";
    qInfo()<< filename;

    QSettings settings(filename,QSettings::Format::IniFormat);

    settings.beginGroup("people");
    settings.setValue("ilker",21);
    settings.sync(); // force saving

    qInfo()<< "Tammy" << settings.value("Tammy",QVariant("Person not found!"));
    qInfo() << "ilker" << settings.value("ilker",QVariant("Person not found!"));

    return a.exec();
}
