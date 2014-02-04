#include "applicationlist.h"
#include <QApplication>

#include "util.h"

int main(int argc, char *argv[])
{
    Util::sharedInit();

    QApplication a(argc, argv);
    a.connect(&a, &QApplication::lastWindowClosed, &a, &QCoreApplication::quit);
    ApplicationList w;
    w.show();

    return a.exec();
}
