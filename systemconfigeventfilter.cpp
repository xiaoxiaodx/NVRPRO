#include "systemconfigeventfilter.h"
#include "customerevent.h"
SystemConfigEventFilter::SystemConfigEventFilter(QObject *parent) : QObject(parent)
{

}

bool SystemConfigEventFilter::eventFilter(QObject *obj, QEvent *event)
{


    if(event->type() == CustomerEvent::eventType()){


        processCustomEvent(obj,event);

        return true;
    }




    return QObject::eventFilter(obj, event);

}


void SystemConfigEventFilter::processCustomEvent(QObject *obj,QEvent *event)
{
    CustomerEvent *customEvent = dynamic_cast<CustomerEvent*>(event);



    if(customEvent->getEventBelong() == BELONG_SYSTEMSET){

        SystemManager *pSystem= dynamic_cast<SystemManager*>(obj);

        switch (customEvent->getEventType()) {
        case TYPE_SYSTEMSET_TEST1:
            pSystem->setText("fdsakjfdkas");
            break;
        }

    }



}
