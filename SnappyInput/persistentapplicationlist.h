#ifndef PERSISTENTAPPLICATIONLIST_H
#define PERSISTENTAPPLICATIONLIST_H

#include <QSettings>
#include <QAbstractListModel>

class PersistentApplicationList : public QSettings
{
    Q_OBJECT
public:
    explicit PersistentApplicationList(QObject *parent = 0);
    QStringList applications() const;
    int numApplications() const;

signals:
    void addedApp(QString appPath);
public slots:
    void addApp(QString appPath);

private:
    static const QString APP_PREFIX;
    int appCount;
};

#endif // PERSISTENTAPPLICATIONLIST_H
