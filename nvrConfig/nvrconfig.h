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
    explicit NvrConfig(QWidget *parent = NULL);
    ~NvrConfig();

    void showDeviceSet();
    void showSystemSet();
public slots:
    void slot_MenuSelectMasterPreview();
    void slot_MenuSelectReplay();
    void slot_MenuSelectDeviceSetting();
    void slot_MenuSelectSystemManagement();
signals:
    void signal_switchWindow(WindowType type);
private:
    void setControlPostion();
    void setMenuItem();
    void initStackedWidget();



    Ui::NvrConfig *ui;

    QPushButton * createSelfBtn(QString btnTxt,QString res);

    DeviceSetting *deviceSetting = NULL;
    SystemManager *systemManager = NULL;


    QPushButton *btnMasterPreview = NULL;
    QPushButton *btnReplay= NULL;
    QPushButton *btnDeviceSetting= NULL;
    QPushButton *btnSystemManagement= NULL;

};

#endif // NVRCONFIG_H
