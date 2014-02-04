#include "util.h"

#include <QCoreApplication>

void Util::sharedInit()
{
    QCoreApplication::setOrganizationName("Kevin Crossan");
    QCoreApplication::setOrganizationDomain("kcrossan.com");
    QCoreApplication::setApplicationName("SnappyInput");
}
