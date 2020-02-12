#ifndef NVRCONFIG_H
#define NVRCONFIG_H

#include <QWidget>
#include <QDialog>

#include "devicesetting.h"

namespace Ui {
class NvrConfig;
}

class NvrConfig : public QDialog
{
    Q_OBJECT

public:
    explicit NvrConfig(QWidget *parent = nullptr);
    ~NvrConfig();

private:
    void setControlPostion();
    void setMenuItem();
    void initStackedWidget();

    QPushButton * createSelfBtn(QString btnTxt,QString res);
    Ui::NvrConfig *ui;

    DeviceSetting *deviceSetting = nullptr;
};

#endif // NVRCONFIG_H
