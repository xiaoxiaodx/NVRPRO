#ifndef DEVICESETTING_H
#define DEVICESETTING_H

#include <QWidget>

namespace Ui {
class DeviceSetting;
}
#include <QTableWidget>
class DeviceSetting : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceSetting(QWidget *parent = nullptr);
    ~DeviceSetting();

private:
    Ui::DeviceSetting *ui;

    void createDeviceTable();
    void deviceTableInsert(int pos,QMap<QString,QVariant> hash);

    void createOSDSetting();
    void adjustOSDWidgetPos();

    void createAlarmSetting();
    void adjustAlarmWidgetPos();

    void createVideoSetting();
    void adjustVideoWidgetPos();

    void createRTMPSetting();
    void adjustRTMPWidgetPos();

    void init();


};

#endif // DEVICESETTING_H
