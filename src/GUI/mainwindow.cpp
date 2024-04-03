#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DropShadowEffect = new QGraphicsDropShadowEffect();

    DropShadowEffect->setBlurRadius(4);
    DropShadowEffect->setColor(QColor(0, 0, 0, 25));
    DropShadowEffect->setOffset(0, 4);

    AddShadowButtons();
    //icon.addPixmap(QPixmap(":/icons/sqaure_root.png"), QIcon::Normal);
    //icon.addPixmap(QPixmap(":/icons/sqaure_root.png"), QIcon::Disabled);



}

void MainWindow::AddShadowButtons(){
    QList<QPushButton *> Buttons = MainWindow::findChildren<QPushButton *>();
    qDebug() << Buttons.size();

    DropShadowEffect = new QGraphicsDropShadowEffect();

    DropShadowEffect->setBlurRadius(4);
    DropShadowEffect->setColor(QColor(0, 0, 0, 25));
    DropShadowEffect->setOffset(0, 4);

    ui->Button1->setGraphicsEffect(DropShadowEffect);

    for (auto but: Buttons) but->setGraphicsEffect(DropShadowEffect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

