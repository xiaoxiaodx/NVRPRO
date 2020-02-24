#ifndef ALARMTYPEMENU_H
#define ALARMTYPEMENU_H

#include <QDialog>

namespace Ui {
class AlarmTypeMenu;
}

class AlarmTypeMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmTypeMenu(QWidget *parent = NULL);
    ~AlarmTypeMenu();
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
private:
    Ui::AlarmTypeMenu *ui;
};

#endif // ALARMTYPEMENU_H
