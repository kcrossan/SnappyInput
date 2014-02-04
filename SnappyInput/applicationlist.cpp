#include "applicationlist.h"
#include "ui_applicationlist.h"

#include <QFileDialog>
#include <QDebug>
#include <QTimer>

ApplicationList::ApplicationList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApplicationList),
    backingList(PersistentApplicationList()),
    backingListModel(&backingList)
{
    ui->setupUi(this);

    createTrayActions();
    createTrayIcon();

    populateAppList();
}

void ApplicationList::createTrayActions()
{
    trayMenu = new QMenu(this);
    createTrayAction("&Restore", SLOT(showNormal()));
    createTrayAction("&Quit", SLOT(close()));
}

QAction* ApplicationList::createTrayAction(const char *label, const char *slot)
{
    QAction *action = new QAction(tr(label), this);
    connect(action, SIGNAL(triggered()), this, slot);
    trayMenu->addAction(action);
    return action;
}

void ApplicationList::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->setIcon(QIcon(":/icons/cursor.ico"));
    connect(trayIcon, &QSystemTrayIcon::activated, this, &ApplicationList::showIfTriggered);
    trayIcon->show();
}

void ApplicationList::showIfTriggered(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::DoubleClick)
    {
        showNormal();
        activateWindow();
    }
}

void ApplicationList::populateAppList()
{
    QListView *list = findChild<QListView *>();
    if(list)
    {
        list->setModel(&backingListModel);
    }
}

void ApplicationList::openAddAppDialog()
{
    addApplication(QFileDialog::getOpenFileName(this,
                   tr("Select Application"), QString(), tr("Executable files (*.exe)")));
}

void ApplicationList::addApplication(const QString &file)
{
    if(file.isNull() || file.isEmpty())
    {
        return;
    }
    qDebug() << "Adding " << file;
    backingListModel.addRow(file);
}

void ApplicationList::changeEvent(QEvent* e)
{
    if(e->type() == QEvent::WindowStateChange && (windowState() & Qt::WindowMinimized))
    {
        QTimer::singleShot(0, this, SLOT(hide()));
    }
    QMainWindow::changeEvent(e);
}

ApplicationList::~ApplicationList()
{
    delete ui;
}
