#ifndef DEVICESETTING_H
#define DEVICESETTING_H

#include <QWidget>
#include <QTableWidget>
namespace Ui {
class DeviceSetting;
}

class DeviceSetting : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceSetting(QWidget *parent = NULL);
    ~DeviceSetting();

private:
    Ui::DeviceSetting *ui;

    void createDeviceTable();
    void createDeviceTableHeader();
    void deviceTableInsert(int pos,QMap<QString,QVariant> hash);
    void showDialog(int deleteIndex);

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
