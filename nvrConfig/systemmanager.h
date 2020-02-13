#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QWidget>

namespace Ui {
class SystemManager;
}

class SystemManager : public QWidget
{
    Q_OBJECT

public:
    explicit SystemManager(QWidget *parent = nullptr);
    ~SystemManager();

private:
    Ui::SystemManager *ui;
    void init();
    void createTimeSetting();
    void adjustTimeSettingWidgetPos();
    void createSystemInfo();
    void adjustSystemInfoWidgetPos();
    void createAlarmQuery();
    void adjustAlarmQueryWidgetPos();
    void createDiskManagement();
    void adjustDiskManagementWidgetPos();
    void createSystemOperation();
    void adjustSystemOperationWidgetPos();
    void createUserManagement();
    void adjustUserManagementWidgetPos();

};

#endif // SYSTEMMANAGER_H
