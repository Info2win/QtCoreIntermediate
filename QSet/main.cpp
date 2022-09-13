#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Bryan" << "Ilker" << "Dilber";
    people.insert("Rex");

    // This is out of order & no duplicates
    foreach(QString person, people)
    {
        qInfo() << person;
    }

    // Very very very fast
    qInfo() << "Is Ilker in collection?"<<people.contains("Ilker");
    return a.exec();
}
