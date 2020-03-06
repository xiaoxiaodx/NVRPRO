#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
public:
    explicit MyLineEdit(QWidget *parent = NULL);
    void setText(QString str);
    QString text();
    void setPasswordInput(bool isPassword);
private:
    bool isPassword = false;
    QString m_text;
};

#endif /
