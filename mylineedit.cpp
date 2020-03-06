#include "mylineedit.h"
#include "QDebug"
MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{

    // qDebug()<<"111dsadsadsa";
}

void MyLineEdit::setPasswordInput(bool ispwd)
{
    isPassword = ispwd;
}

void MyLineEdit::setText(QString str)
{

    m_text = str;
    if(isPassword){

        QString str1(m_text.length(),'*');
        QLineEdit::setText(str1);

    }else {

        QLineEdit::setText(m_text);
    }
}

QString MyLineEdit::text()
{
    return m_text;
}
