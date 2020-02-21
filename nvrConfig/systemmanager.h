#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QWidget>
#include "alarmtypemenu.h"
#include "cameramenu.h"
#include <QMenu>
#include "videoReplay/mycalendar.h"
#include "util.h"
#include "timeselectdialog.h"
namespace Ui {
class SystemManager;
}


class SystemManager : public QWidget
{
    Q_OBJECT

public:
    explicit SystemManager(QWidget *parent = nullptr);
    ~SystemManager();

private slots:

    void on_pushButton_date_clicked();

    void on_pushButton_time_clicked();

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
    AlarmTypeMenu *alarmtypeMenu = nullptr;
    CameraMenu *cameraMenu = nullptr;
    QMenu *dateSelectMenu = nullptr;

    DateSelectType currentDateSelectType;
    MyCalendar *myCalendar = nullptr;
    TimeSelectDialog *timeSelectDialog= nullptr;
};

#endif // SYSTEMMANAGER_H
