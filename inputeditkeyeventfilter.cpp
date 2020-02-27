#include "inputeditkeyeventfilter.h"
#include <QDebug>
#include <QLineEdit>
#include <QMouseEvent>
#include "mainwindow.h"
InputEditKeyEventFilter::InputEditKeyEventFilter(QObject *parent) : QObject(parent)
{

}

bool InputEditKeyEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == MyKeyPressEvent::eventType()) {
        MyKeyPressEvent *customerEvent = dynamic_cast<MyKeyPressEvent*>(event);
        qDebug() <<"InputEditKeyEventFilter:"<< customerEvent->getValueString();

        QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(obj);
        QString currentStr = lineEdit->text();
        QString keyStr = customerEvent->getValueString();
        QString setStr = currentStr;
        if(keyStr.compare("enter")==0){

        }else if (keyStr.compare("Space")==0) {
            setStr += " ";
        }else if (keyStr.compare("backspace")==0) {
            setStr = setStr.left(setStr.length() - 1);
        }else {
            setStr += keyStr;
        }

        lineEdit->setText(setStr);

        return true;
    } else if(event->type() == QEvent::MouseButtonRelease){

        QWidget *widget = dynamic_cast<QWidget*>(obj);

        QPoint topleftGlobal = widget->mapToGlobal(QPoint(0,0));

        VirtualKeyboard *myVir = MainWindow::virtualKeyboard;
        Q_ASSERT(myVir != NULL);

        myVir->move(topleftGlobal.x(),topleftGlobal.y()+widget->height());
        myVir->show();


        return  false;
    } else if(event->type() == QEvent::FocusOut){


        qDebug()<<"失去焦点";
        return QObject::eventFilter(obj, event);

    }else {

        return QObject::eventFilter(obj, event);
    }
}

