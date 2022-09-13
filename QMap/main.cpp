#include <QCoreApplication>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString,int> ages;
    ages.insert("Brayn",44);
    ages.insert("Ilker",21);
    ages.insert("Dilber",52);

    qInfo() << "Keys:" << ages.keys();
    qInfo() <<"Values:" << ages.values();
    qInfo()<< "Ilker is" << ages.value("Ilker") << "years old.";
    qInfo()<<"Does it contain Dilber?" << ages.contains("Dilber");
    ages.remove("Dilber");
    qInfo()<<"Does it contain Dilber?" << ages.contains("Dilber");
    foreach(QString key, ages.keys())
    {
        qInfo()<< key << "=" << ages[key];
    }
    qInfo()<< "Test" << ages.value("Test",-1);
    qInfo()<< "Test" << ages["Test"];
    ages["Brayn"] = 99;
    qInfo() << "Brayn" << ages.value("Brayn",-1);
    ages["Test"] = 99; // if there is no 'Test' it inserts it
    qInfo()<< "Test" << ages.value("Test",-1);
    return a.exec();
}
