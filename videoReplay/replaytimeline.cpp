#include "replaytimeline.h"
#include "ui_replaytimeline.h"
#include <QPainter>
#include <QDateTime>
#include <QDebug>
#include <QButtonGroup>
ReplayTimeline::ReplayTimeline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplayTimeline)
{
    ui->setupUi(this);

    replayCurrentTime.setHMS(13,20,15);
}
ReplayTimeline::~ReplayTimeline()
{
    delete ui;
}

void ReplayTimeline::init()
{

    ui->widget_play->setGeometry(0,0,1920,41);
    ui->pushButton_24h->move(29,11);
    ui->pushButton_2h->move(29+60,11);
    ui->pushButton_1h->move(29+60*2,11);
    ui->pushButton_30min->move(29+60*3,11);

    QButtonGroup *buttonGround = new QButtonGroup(this);
    buttonGround->addButton(ui->pushButton_24h);
    buttonGround->addButton(ui->pushButton_2h);
    buttonGround->addButton(ui->pushButton_1h);
    buttonGround->addButton(ui->pushButton_30min);
    buttonGround->setExclusive(true);

    connect(ui->pushButton_24h,&QPushButton::clicked,this,&ReplayTimeline::slot_24hSelect);
    connect(ui->pushButton_2h,&QPushButton::clicked,this,&ReplayTimeline::slot_2hSelect);
    connect(ui->pushButton_1h,&QPushButton::clicked,this,&ReplayTimeline::slot_1hSelect);
    connect(ui->pushButton_30min,&QPushButton::clicked,this,&ReplayTimeline::slot_30mSelect);

    ui->widget_date->move(302,11);

    ui->pushButton_slow->move(909,7);
    ui->pushButton_play->move(955,7);
    ui->pushButton_fast->move(1002,7);

    ui->label_normalimg->move(1298,17);
    ui->label_normal->move(1310,13);
    ui->label_alarmimg->move(1412,17);
    ui->label_alarm->move(1424,13);
    ui->label_novideoimg->move(1526,17);
    ui->label_novideo->move(1538,13);

    ui->label_voice->move(1630,12);
    ui->horizontalSlider->move(1656,17);
    ui->pushButton_video1->move(1823,5);
    ui->pushButton_video4->move(1860,5);


    initTimeLineInterval();
}


void ReplayTimeline::slot_24hSelect()
{
    scaleType = TIMELINE24H;
    this->update();
}
void ReplayTimeline::slot_2hSelect()
{
    scaleType = TIMELINE2H;
    this->update();
}
void ReplayTimeline::slot_1hSelect()
{
    scaleType = TIMELINE1H;
    this->update();
}
void ReplayTimeline::slot_30mSelect()
{
    scaleType = TIMELINE30M;
    this->update();
}

void ReplayTimeline::initTimeLineInterval()
{
    {
        TimeInterval *timeInterval24h = new TimeInterval;
        timeInterval24h->type = TIMELINE24H;
        timeInterval24h->startTime = QTime(0,0,0);
        timeInterval24h->endTime = QTime(23,59,59,59);
        listTimeInterval24H.append(timeInterval24h);
    }
    for (int i=0;i<24;i+=2) {
        TimeInterval *timeInterval2h = new TimeInterval();
        timeInterval2h->type = TIMELINE2H;
        timeInterval2h->startTime = QTime(i,0,0);
        timeInterval2h->endTime = QTime(i+2,0,0);
        listTimeInterval2H.append(timeInterval2h);
    }

    for (int i=0;i<24;i++) {
        TimeInterval *timeInterval1h = new TimeInterval();
        timeInterval1h->type = TIMELINE1H;
        timeInterval1h->startTime = QTime(i,0,0);
        timeInterval1h->endTime = QTime(i+1,0,0);
        listTimeInterval1H.append(timeInterval1h);
    }

    //一个小时中有2个区间
    for (int i=0;i<24;i++) {
        TimeInterval *timeInterval30m1 = new TimeInterval();
        timeInterval30m1->type = TIMELINE30M;
        timeInterval30m1->startTime = QTime(i,0,0);
        timeInterval30m1->endTime = QTime(i,30,0);
        listTimeInterval30M.append(timeInterval30m1);

        TimeInterval *timeInterval30m2 = new TimeInterval;
        timeInterval30m2->type = TIMELINE30M;
        timeInterval30m2->startTime = QTime(i,30,0);
        timeInterval30m2->endTime = QTime(i+1,0,0);
        listTimeInterval30M.append(timeInterval30m2);
    }
}

TimeInterval* ReplayTimeline::findInterval(QList<TimeInterval*> &list,QTime &time)
{

   // qDebug()<<"当前值："<<time.toString("hh:mm:ss");
    for (int i=0;i<list.size();i++) {
        TimeInterval *timeI = list.at(i);
        QTime tmpStart = timeI->startTime;
        QTime tmpEnd = timeI->endTime;
        //qDebug()<<"区间值:"<<tmpStart.toString("hh:mm:ss")<<" "<<tmpEnd.toString("hh:mm:ss");
        if(time>= tmpStart && time<=tmpEnd)
            return timeI;
    }

    return  NULL;
}

void ReplayTimeline::paintEvent(QPaintEvent * event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);   //线条抗锯齿
    painter.setRenderHint(QPainter::TextAntialiasing);


    drawBg(painter);

}

void ReplayTimeline::drawBg(QPainter &painter){
    //时间轴所在的矩形
    QRectF rectTimeLine(31,75,1838,67);
    //绘制大背景
    painter.setPen(QPen(QColor("#252525"),1));
    painter.setBrush(QBrush(QColor("#252525")));
    painter.drawRect(0,41,1920,113);

    //绘制时间轴背景
    painter.save();
    painter.setBrush(QBrush(QColor("#FFFFFF")));
    painter.drawRect(rectTimeLine);
    painter.restore();
    //绘制3条水平分割线

    painter.drawLine(QPointF(rectTimeLine.x(),rectTimeLine.y() + 17),QPointF(rectTimeLine.x()+rectTimeLine.width(),rectTimeLine.y() + 17));
    painter.drawLine(QPointF(rectTimeLine.x(),rectTimeLine.y() + 34),QPointF(rectTimeLine.x()+rectTimeLine.width(),rectTimeLine.y() + 34));
    painter.drawLine(QPointF(rectTimeLine.x(),rectTimeLine.y() + 51),QPointF(rectTimeLine.x()+rectTimeLine.width(),rectTimeLine.y() + 51));
    //绘制刻度
    drawScale(painter,scaleType);

}


void ReplayTimeline::drawScale(QPainter &painter,IntervalType type)
{
    //时间轴所在的矩形
    QRectF rectTimeLine(31,75,1838,67);

    int splictlineCount ;
    qreal contentWidth ;
    //字体
    QFont newFont;
    newFont.setPixelSize(12);
    newFont.setFamily("HelveticaNeue");
    QFontMetrics fontMetrics(newFont);
    painter.setFont(newFont);
    splictlineCount = 24-1;
    contentWidth = (rectTimeLine.width()-splictlineCount) / 24;

    TimeInterval *timeInterval = NULL;
    qreal valuePerScale;
    int markInterval;

    //在这里获取：回放时间点所在的区间，区间的起始位置，每刻度的长度（单位分钟）,每隔几个刻度显示一次标注
    if(type == TIMELINE24H){
        timeInterval = findInterval(listTimeInterval24H,replayCurrentTime);
        valuePerScale = 60;
        markInterval = 1;
    }else if (type == TIMELINE2H) {
        timeInterval = findInterval(listTimeInterval2H,replayCurrentTime);
        valuePerScale = 5;
        markInterval = 1;
    }else if (type == TIMELINE1H) {
        timeInterval = findInterval(listTimeInterval1H,replayCurrentTime);
        valuePerScale = 2.5;
        markInterval = 2;
    }else if (type == TIMELINE30M) {
        timeInterval = findInterval(listTimeInterval30M,replayCurrentTime);
        valuePerScale = 1.25;
        markInterval = 4;
    }

    if(timeInterval == NULL){
        qDebug()<<"未找到指定区间";
        return;
    }

    QTime startT = timeInterval->startTime;
    for (int num = 0;num<25;num++) {
        qreal linex = rectTimeLine.x() + (contentWidth+1)*num;
        painter.drawLine(QPointF(linex,rectTimeLine.y()),QPointF(linex,rectTimeLine.y()+rectTimeLine.height()));

        if(num % markInterval != 0)
            continue;
        painter.save();
        painter.setPen(QPen(QColor("#ffffff"),1));
        //每刻度1.25分钟
        int min = num*valuePerScale;
        QTime time;
        if(min<60){
            time.setHMS(startT.hour(),min,0);
        }else {
            int divisorH = min/60;  //除数
            int remainderH = min%60;//余数
            time.setHMS(startT.hour()+divisorH,remainderH,0);
        }

        QString showtimeStr = time.toString("hh:mm");
        if(min == 24*60)
            showtimeStr = "24:00";
        QRect rect = fontMetrics.boundingRect(showtimeStr);
        painter.drawText(linex - rect.width()/2,rectTimeLine.y() - rect.height(),showtimeStr);
        painter.restore();
    }
}

void ReplayTimeline::setDate(QDate date)
{
    ui->label_date->setText(date.toString("yyyy-MM-dd"));
}
void ReplayTimeline::on_pushButton_date_clicked()
{
   emit signal_popDateDialog();
}


