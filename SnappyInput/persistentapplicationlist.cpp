#include "persistentapplicationlist.h"

#include <QDebug>

const QString PersistentApplicationList::APP_PREFIX = QString("app");

PersistentApplicationList::PersistentApplicationList(QObject *parent) :
    QSettings(parent), appCount(applications().size())
{
    connect(this, &PersistentApplicationList::addedApp, this, &QSettings::sync);
    qDebug() << "Restored " << appCount << " applications";
}

void PersistentApplicationList::addApp(QString appPath)
{
    //If transitioning to structured data, use beginWriteArray
    setValue(APP_PREFIX + QString::number(appCount++), appPath);
    emit addedApp(appPath);
}

QStringList PersistentApplicationList::applications() const
{
    QStringList applications = allKeys().filter(APP_PREFIX);
    for(QStringList::Iterator keySrc = applications.begin(); keySrc != applications.end(); keySrc++)
    {
        *keySrc = value(*keySrc).toString();
    }
    return applications;
}

int PersistentApplicationList::numApplications() const
{
    return appCount;
}
