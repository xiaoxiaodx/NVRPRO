#ifndef INPUTEDITKEYEVENTFILTER_H
#define INPUTEDITKEYEVENTFILTER_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include "mykeypressevent.h"
#include "virtualkeyboard.h"
class InputEditKeyEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit InputEditKeyEventFilter(QObject *parent = nullptr);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:

public slots:

};

#endif // INPUTEDITKEYEVENTFILTER_H
