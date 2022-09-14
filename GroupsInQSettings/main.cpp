#include <QCoreApplication>
#include <QSettings>

void saveAge(QSettings &setting, QString group,QString name,int age)
{
    setting.beginGroup(group);
    setting.setValue(name,age);
    setting.endGroup();
}

int getAge(QSettings &setting, QString group,QString name)
{
    setting.beginGroup(group);
    if(!setting.contains(name))
    {
        qWarning() << "Does not contain" << name << "in" << group;
    }
    bool ok;
    int value = setting.value(name).toInt(&ok);
    setting.endGroup();
    if(!ok)
    {
        qWarning() << "Could not convert to Integer";
        return 0;
    }
    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Info2win");
    QCoreApplication::setApplicationName("Group in Settings Test App");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());
    saveAge(settings,"people","ilker",21);
    saveAge(settings,"beer","tuborg",75);
    saveAge(settings,"beer","ilker",1);

    qInfo() << "Tuborg" << getAge(settings,"beer","tuborg");
    qInfo() << "ilker (people)" << getAge(settings,"people","ilker");
    qInfo() << "ilker (beer)" << getAge(settings,"beer","ilker");

    return a.exec();
}
