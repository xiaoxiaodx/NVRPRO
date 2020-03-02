#ifndef SYSTEMCONFIGEVENTFILTER_H
#define SYSTEMCONFIGEVENTFILTER_H


#include <QObject>
#include <nvrConfig/systemmanager.h>
#include "customerevent.h"


class SystemConfigEventFilter: public QObject
{
public:
    SystemConfigEventFilter(QObject *parent = NULL);




protected:
    bool eventFilter(QObject *obj, QEvent *event);


private:
    void processCustomEvent(QObject *obj, QEvent *event);
};
#endif // SYSTEMCONFIGEVENTFILTER_H
