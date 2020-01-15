#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>



#include "timezonesetting.h"
#include "passwordsetting.h"
#include "welcome.h"
#include "videowindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void paintEvent(QPaintEvent*);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void on_btnAudio_clicked();
    void on_btnBeer_clicked();
    void on_btnHDMI_clicked();
    void on_btnNetWork_clicked();
    void on_btnVGA_clicked();
    void on_btnPan_clicked();

private:
    QPushButton *btnAudio;
    QPushButton *btnBeer;
    QPushButton *btnHDMI;
    QPushButton *btnNetWork;
    QPushButton *btnVGA;
    QPushButton *btnPan;


private:
    Ui::MainWindow *ui;

    void createDialog_timeZoneSetting();
    void createDialog_passwordSetting();
    void createDialog_welcome();
    void createVideoWindow(int n);


    void drawVideoRect(QPainter *paint,int nxn);
    void drawCloudControl(QPainter *paint);


    int const rectSpace = 2;//分屏的时候，相邻矩形的边距
    int const videoN = 2;//几乘几的视频显示

    Timezonesetting *timeZoneSetting = nullptr;
    PasswordSetting *passwordSetting = nullptr;
    Welcome *welcome = nullptr;
};

#endif // MAINWINDOW_H
