#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QWidget>
#include "alarmtypemenu.h"
#include "cameramenu.h"
#include <QMenu>

#include "util.h"
#include "timeselectdialog.h"
#include "dcalendardialog.h"
#include "virtualkeyboard.h"
namespace Ui {
class SystemManager;
}


class SystemManager : public QWidget
{
    Q_OBJECT

public:
    explicit SystemManager(QWidget *parent = NULL);
    ~SystemManager();



    void setText(QString str);

protected:
    bool event(QEvent *event);
private slots:

    void on_pushButton_date_clicked();

    void on_pushButton_time_clicked();


    void slot_alarmTypeMenuClick();
    void slot_channelMenuClick();
    void slot_timeChange(QTime time);
    void slot_dateChange(QString  datestr1,QString  datestr2);
    void on_TimeSetpushButton_url_clicked();

private:
    Ui::SystemManager *ui;
    void init();
    void createTimeSetting();
    void adjustTimeSettingWidgetPos();
    void createSystemInfo();
    void adjustSystemInfoWidgetPos();

    void createAlarmQuery();
    void adjustAlarmQueryWidgetPos();
    void createAlarmQueryTable();
    void createDeviceTableHeader();
    void alarmQueryTableInsert(int row_count,QMap<QString,QVariant> map);

    void createDiskManagement();
    void adjustDiskManagementWidgetPos();
    void createSystemOperation();
    void adjustSystemOperationWidgetPos();
    void createUserManagement();
    void adjustUserManagementWidgetPos();


    void popCalendar();

    AlarmTypeMenu *alarmtypeMenu = NULL;
    CameraMenu *cameraChannelMenu = NULL;

    DateSelectType currentDateSelectType;
    DCalendarDialog *myCalendar = NULL;
    TimeSelectDialog *timeSelectDialog= NULL;
    VirtualKeyboard *keyBoard =NULL;
};

#endif // SYSTEMMANAGER_H
