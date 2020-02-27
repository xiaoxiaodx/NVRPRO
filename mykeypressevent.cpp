#include "mykeypressevent.h"

MyKeyPressEvent::Type MyKeyPressEvent::myEventType = QEvent::None;

MyKeyPressEvent::MyKeyPressEvent(QString valueString) : QEvent(eventType())
{
    m_String = valueString;
}

MyKeyPressEvent::~MyKeyPressEvent()
{

}

MyKeyPressEvent::Type MyKeyPressEvent::eventType()
{
    // 创建事件Type
    if (myEventType == QEvent::None)
        myEventType = (QEvent::Type)QEvent::registerEventType();

    return myEventType;
}

QString MyKeyPressEvent::getValueString(void)
{
    return m_String;
}
