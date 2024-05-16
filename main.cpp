#include "mainwindow.h"

#include <QApplication>

#include <algorithm> // 用于 std::min 函数
#include <cmath>     // 用于 pow 函数
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("政委的导弹伤害计算器");
    w.show();
    return a.exec();



}
