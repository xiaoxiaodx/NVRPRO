#ifndef MYKEYPRESSEVENT_H
#define MYKEYPRESSEVENT_H

#include <QObject>
#include <QEvent>

class MyKeyPressEvent : public QEvent
{

public:
    MyKeyPressEvent(QString valueString = "");
    ~MyKeyPressEvent();

    static Type eventType();
    QString getValueString(void);

private:
    static Type myEventType;
    QString m_String;
};

#endif // MYKEYPRESSEVENT_H
