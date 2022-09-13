#include <QCoreApplication>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList names = {"Ilker"};
    names << "Tammy" << "Rango";
    names.append("Dilber");

    names.replaceInStrings("a","@");
    qInfo() << names;
    names.replaceInStrings("@","a");
    qInfo()<< names;
    names.sort();
    qInfo()<< names;
    QString people = names.join(",");
    qInfo() << people;
    QStringList myfilteredlist = names.filter("r");
    qInfo() << myfilteredlist;
    QString me = "Ilker";
    qInfo() << "Contains?" << names.contains(me);
    qInfo()<< "Index of:" << names.indexOf(me);
    qInfo() << "Value" << names.at(names.indexOf(me));
    return a.exec();
}
