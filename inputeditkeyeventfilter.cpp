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

    QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(obj);

    Q_ASSERT(lineEdit);

    if (event->type() == MyKeyPressEvent::eventType()) {
        MyKeyPressEvent *customerEvent = dynamic_cast<MyKeyPressEvent*>(event);
        qDebug() <<"InputEditKeyEventFilter:"<< customerEvent->getValueString();
        QString currentStr = lineEdit->text();
        QString keyStr = customerEvent->getValueString();
        QString setStr = "";
        int curCursorPos = lineEdit->cursorPosition();
        if(keyStr.compare("enter")==0){
            return true;
        }else if (keyStr.compare("Space")==0) {
            setStr = currentStr.insert(curCursorPos,' ');
            curCursorPos+=1;
        }else if (keyStr.compare("backspace")==0) {
            if(curCursorPos > 0)
                setStr = currentStr.remove(--curCursorPos,1);
            else
                return true;
            qDebug()<<"backspace:"<<currentStr<<"   "<<setStr<<"    "<<curCursorPos;

        }else {
            setStr += currentStr.insert(curCursorPos,keyStr);
            curCursorPos+=1;
        }

        qDebug() <<"cursorPosition:"<< curCursorPos<<"    "<<setStr;

        lineEdit->setText(setStr);
        lineEdit->setCursorPosition(curCursorPos);

        return true;
    } else if(event->type() == QEvent::MouseButtonRelease){

        QLineEdit *widget = dynamic_cast<QLineEdit*>(obj);

        QPoint topleftGlobal = widget->mapToGlobal(QPoint(0,0));

        VirtualKeyboard *myVir = MainWindow::virtualKeyboard;
        Q_ASSERT(myVir != NULL);

        myVir->move(topleftGlobal.x(),topleftGlobal.y()+widget->height());
        if(myVir->isHidden())
            myVir->show();
        return  false;
    }else if(event->type() == QEvent::FocusIn){




        return  false;

    } else if(event->type() == QEvent::FocusOut){
        //qDebug()<<"失去焦点："<<lineEdit->objectName();

        return false;

    }else {

        return QObject::eventFilter(obj, event);
    }
}

