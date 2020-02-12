#ifndef CUSTOMEREVENT_H
#define CUSTOMEREVENT_H

#include <QObject>
#include <QEvent>
class CustomerEvent : public QEvent
{
public:
    CustomerEvent(QString valueString = "");
    ~CustomerEvent();

    static Type eventType();
    QString getValueString(void);

private:
    static Type m_EventType;
    QString m_String;
};

#endif // CUSTOMEREVENT_H
