#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm> // 用于 std::min 函数
#include <cmath>     // 用于 pow 函数

double drf[40]={0,0.882,0,1.00,0,0.644,0.882,0.682,0,0.944,0,0.604,0.561,0.682,0.604,0,0.882,0.735,0.908,0.882,0,0.944,0.967,0.967,0,0.682,0.583,0.882,0.682,0,0.882,0.820,0.895,0,0.4,0.5,0.7};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str;//创建一个QString字符串，命名为str
    str=ui->DaoDanJiChuShangHai->text();//将导弹基础伤害中的字符串存入str
    double Num_DaoDanJiChuShangHai=str.toDouble();//将str里面的字符串转为浮点数,下同
    str=ui->MuBiaoBanJin->text();
    double Num_MuBiaoBanJin=str.toDouble();
    str=ui->DaoDanBaoZhaBanJin->text();
    double Num_DaoDanBaoZhaBanJin=str.toDouble();
    str=ui->DaoDanBaoZhaSuDu->text();
    double Num_DaoDanBaoZhaSuDu=str.toDouble();
    str=ui->MuBiaoSuDu->text();
    double Num_MuBiaoSuDu=str.toDouble();

    int index = ui->drfBox->currentIndex();//获得索引

    double numerator = Num_MuBiaoBanJin * Num_DaoDanBaoZhaSuDu;//计算公式，下同
    double denmoinator =Num_DaoDanBaoZhaBanJin*Num_MuBiaoSuDu;
    double exponent=pow(numerator/denmoinator,drf[index]);
    double minValue=std::min({1.0,Num_MuBiaoBanJin/Num_DaoDanBaoZhaBanJin,exponent});
    double damage=Num_DaoDanJiChuShangHai*minValue;

    ui->ZuiZhongZaoChengShangHai->setNum(damage);//用Qlable输出浮点数damage



}


void MainWindow::on_drfBox_activated(int index)
{
    ui->Num_drf->setNum(drf[index]);//用Qlable输出浮点数drf
}

