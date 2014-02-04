#include "persistentapplicationlistmodel.h"

PersistentApplicationListModel::PersistentApplicationListModel(PersistentApplicationList *object) :
    QAbstractListModel(),
    object(object)
{
}

int PersistentApplicationListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }
    return object->numApplications();
}

QVariant PersistentApplicationListModel::data(const QModelIndex &index, int role) const
{
    QStringList applications = object->applications();
    if(index.row() >= applications.size() || index.row() < 0 || role != Qt::DisplayRole)
    {
        return QVariant();
    }
    return applications[index.row()];
}

void PersistentApplicationListModel::addRow(QString appPath)
{
    beginInsertRows(QModelIndex(), object->numApplications(), object->numApplications());
    object->addApp(appPath);
    endInsertRows();
}
