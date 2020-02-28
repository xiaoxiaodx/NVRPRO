#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.showFullScreen();


//    QFontDatabase SS;
//    qDebug()<<"fonts:"<<SS.families();
    return a.exec();
}
