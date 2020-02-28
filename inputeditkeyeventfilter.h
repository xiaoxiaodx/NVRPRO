#ifndef INPUTEDITKEYEVENTFILTER_H
#define INPUTEDITKEYEVENTFILTER_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include "mykeypressevent.h"
#include "virtualkeyboard.h"
#include <QLineEdit>
class InputEditKeyEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit InputEditKeyEventFilter(QObject *parent = nullptr);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:

public slots:

private:
    QLineEdit *currentFocusEdit = NULL;
    bool isHideCursor = false;
};

#endif // INPUTEDITKEYEVENTFILTER_H
