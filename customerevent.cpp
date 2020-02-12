#include "customerevent.h"
QEvent::Type CustomerEvent::m_EventType = QEvent::None;

CustomerEvent::CustomerEvent(QString valueString) : QEvent(eventType())
{
    m_String = valueString;
}

CustomerEvent::~CustomerEvent()
{

}

QEvent::Type CustomerEvent::eventType()
{
    // 创建事件Type
    if (m_EventType == QEvent::None)
        m_EventType = (QEvent::Type)QEvent::registerEventType();

    return m_EventType;
}

QString CustomerEvent::getValueString(void)
{
    return m_String;
}
