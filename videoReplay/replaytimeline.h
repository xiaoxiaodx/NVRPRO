#ifndef REPLAYTIMELINE_H
#define REPLAYTIMELINE_H

#include <QWidget>
#include <QTime>
#include <QMap>
#include <QList>
#include "mycalendar.h"
#include "util.h"
namespace Ui {
class ReplayTimeline;
}


class ReplayTimeline : public QWidget
{
    Q_OBJECT
public:
    explicit ReplayTimeline(QWidget *parent = nullptr);
    ~ReplayTimeline();
    void init();
    void setDate(QDate date);
signals:
    void signal_popDateDialog();

protected:
    void paintEvent(QPaintEvent * event);
private slots:
    void on_pushButton_date_clicked();

private:
    Ui::ReplayTimeline *ui;
    void initTimeLineInterval();
    //在指定区间链表中寻找包含指定时间的区间
    TimeInterval *findInterval(QList<TimeInterval*> &list,QTime &time);

    void drawBg(QPainter &painter);
    void drawScale(QPainter &painter,IntervalType type);



    IntervalType scaleType = TIMELINE24H;//刻度类型

    QTime replayCurrentTime;
    QList<TimeInterval*> listTimeInterval24H;
    QList<TimeInterval*> listTimeInterval2H;
    QList<TimeInterval*> listTimeInterval1H;
    QList<TimeInterval*> listTimeInterval30M;

    //4个回放窗口的不同类型区间链表
    QList<TimeInterval*> listVideoInterval1;
    QList<TimeInterval*> listVideoInterval2;
    QList<TimeInterval*> listVideoInterval3;
    QList<TimeInterval*> listVideoInterval4;

    MyCalendar *myCalendar = nullptr;
};

#endif // REPLAYTIMELINE_H
