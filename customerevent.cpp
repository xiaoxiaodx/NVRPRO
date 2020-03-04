#include "customerevent.h"
QEvent::Type CustomerEvent::m_EventType = QEvent::None;

CustomerEvent::CustomerEvent(EventBelong belong,CustomerEventType type,QVariant par) : QEvent(eventType())
{
    m_type = type;
    m_par = par;
    m_belong = belong;
}

CustomerEvent::~CustomerEvent()
{

}

EventBelong CustomerEvent::getEventBelong(void)
{
    return m_belong;
}
#include <QDebug>
QEvent::Type CustomerEvent::eventType()
{
    // 创建事件Type
    if (m_EventType == QEvent::None)
        m_EventType = (QEvent::Type)QEvent::registerEventType();

    return m_EventType;
}

QVariant CustomerEvent::getEventPar(void)
{
    return m_par;
}

CustomerEventType CustomerEvent::getEventType(void)
{
    return m_type;
}
