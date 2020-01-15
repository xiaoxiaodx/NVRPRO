#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QWidget>

namespace Ui {
class VideoWindow;
}

class VideoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr,int mW = 0,int mH = 0 );
    ~VideoWindow();

private:
    Ui::VideoWindow *ui;
    void setControlPostion();

    int mWidth = 0;//提前获取的宽高保存在这
    int mHeight = 0;
};

#endif // VIDEOWINDOW_H
