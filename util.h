#ifndef UTIL_H
#define UTIL_H

#include <QTime>
#include <QDebug>
enum IntervalType{
    VIDEOLOSS = 0,
    VIDEONORMAL,
    VIDEOALARM,
    TIMELINE24H=10,
    TIMELINE2H,
    TIMELINE1H,
    TIMELINE30M,
};
class TimeInterval{
public:
    IntervalType type;
    QTime startTime;
    QTime endTime;
};

enum WindowType{

    MASTERPREVIEW = 0,
    REPLAYVIDEO,
    SYSTEMSET,
    DEVICESET,
    NONE,
};

enum DateSelectType{
    STARTTIME,
    ENDTIME,
};

#endif // UTIL_H
