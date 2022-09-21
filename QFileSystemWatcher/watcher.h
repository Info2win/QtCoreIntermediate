#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QDir>
#include <QTimer>

class Watcher : public QObject
{
    Q_OBJECT
private:
    QFileSystemWatcher fsw;
public:
    explicit Watcher(QObject *parent = nullptr);
signals:
public slots:
    void directoryChanged(const QString &path);
    void fileChanged(const QString &path);


};

#endif // WATCHER_H
