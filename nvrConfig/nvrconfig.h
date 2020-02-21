#ifndef NVRCONFIG_H
#define NVRCONFIG_H

#include <QDialog>
#include "util.h"
#include "devicesetting.h"
#include "systemmanager.h"

namespace Ui {
class NvrConfig;
}


class NvrConfig : public QDialog
{
    Q_OBJECT

public:
    explicit NvrConfig(QWidget *parent = nullptr);
    ~NvrConfig();

    void showDeviceSet();
    void showSystemSet();
signals:
    void signal_switchWindow(WindowType type);
private:
    void setControlPostion();
    void setMenuItem();
    void initStackedWidget();



    Ui::NvrConfig *ui;

    QPushButton * createSelfBtn(QString btnTxt,QString res);

    DeviceSetting *deviceSetting = nullptr;
    SystemManager *systemManager = nullptr;


    QPushButton *btnMasterPreview = nullptr;
    QPushButton *btnReplay= nullptr;
    QPushButton *btnDeviceSetting= nullptr;
    QPushButton *btnSystemManagement= nullptr;

};

#endif // NVRCONFIG_H
