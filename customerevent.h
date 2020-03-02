#ifndef CUSTOMEREVENT_H
#define CUSTOMEREVENT_H

#include <QObject>
#include <QEvent>
#include <QVariant>

enum EventBelong{
    BELONG_MAINWINDOW = 0,
    BELONG_SYSTEMSET,
};

enum CustomerEventType{
    TYPE_NONE = -1,
    TYPE_SYSTEMSET_TEST1,

};

class CustomerEvent : public QEvent
{
public:



    CustomerEvent(EventBelong belong=BELONG_MAINWINDOW,CustomerEventType type= TYPE_NONE,QVariant par = 0);
    ~CustomerEvent();


    static Type eventType();
    CustomerEventType getEventType(void);
    QVariant getEventPar(void);
    EventBelong getEventBelong(void);
private:
    static Type m_EventType;
    CustomerEventType m_type;
    EventBelong m_belong;
    QVariant m_par;
};

#endif // CUSTOMEREVENT_H
