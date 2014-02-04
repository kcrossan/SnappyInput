#ifndef APPLICATIONLIST_H
#define APPLICATIONLIST_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "persistentapplicationlistmodel.h"

namespace Ui {
class ApplicationList;
}

class ApplicationList : public QMainWindow
{
    Q_OBJECT

public:
    explicit ApplicationList(QWidget *parent = 0);
    ~ApplicationList();

public slots:
    void openAddAppDialog();
    void addApplication(const QString &file);

protected:
    virtual void changeEvent(QEvent* e);

private slots:
    void showIfTriggered(QSystemTrayIcon::ActivationReason reason);

private:
    void createTrayIcon();
    void createTrayActions();
    QAction* createTrayAction(const char *label, const char *slot);
    void populateAppList();

    Ui::ApplicationList *ui;

    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;

    PersistentApplicationList backingList;
    PersistentApplicationListModel backingListModel;
};

#endif // APPLICATIONLIST_H
