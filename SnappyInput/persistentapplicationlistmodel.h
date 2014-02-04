#ifndef PERSISTENTAPPLICATIONLISTMODEL_H
#define PERSISTENTAPPLICATIONLISTMODEL_H

#include <QAbstractListModel>
#include "persistentapplicationlist.h"

class PersistentApplicationListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PersistentApplicationListModel(PersistentApplicationList *object);

    virtual int PersistentApplicationListModel::rowCount(const QModelIndex &parent) const;
    virtual QVariant PersistentApplicationListModel::data(const QModelIndex &index, int role) const;

    void addRow(QString appPath);

signals:

public slots:

private:
    PersistentApplicationList *object;
};

#endif // PERSISTENTAPPLICATIONLISTMODEL_H
