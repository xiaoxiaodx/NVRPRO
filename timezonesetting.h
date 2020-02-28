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

   signals:
    void signal_timezoneStr(QString);
private slots:
    void on_pushButton_next_clicked();

private:
    Ui::Timezonesetting *ui;
    void setControlPostion();
};

#endif // TIMEZONESETTING_H
