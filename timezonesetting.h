#ifndef TIMEZONESETTING_H
#define TIMEZONESETTING_H

#include <QDialog>

namespace Ui {
class Timezonesetting;
}

class Timezonesetting : public QDialog
{
    Q_OBJECT

public:
    explicit Timezonesetting(QWidget *parent = NULL);
    ~Timezonesetting();

private:
    Ui::Timezonesetting *ui;
    void setControlPostion();
};

#endif // TIMEZONESETTING_H
