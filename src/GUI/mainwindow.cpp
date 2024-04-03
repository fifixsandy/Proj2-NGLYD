#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bool SucConnest = connect(ui->Button2, &QPushButton::clicked ,this,&MainWindow::TestButtonPrint);
    #ifdef DEBUG
    qInfo() << "Conection Button2 to Slot:" << SucConnest;
    #endif

    AddShadowToButtons();
    ConfDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConfDisplay(){
    QRegularExpression rx("[0-9]+[.]{0,1}[0-9]*");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->Display->setValidator(validator);
}

void MainWindow::TestButtonPrint()
{
    ui->Display->setText("12345");
    #ifdef DEBUG
         qInfo() << "TestPrint";
    #endif
}

void MainWindow::AddShadowToButtons(){
    QList<QPushButton *> Buttons = MainWindow::findChildren<QPushButton *>();

    for (auto but: Buttons){
        but->setGraphicsEffect(CreateShadow());
    }
}

QGraphicsDropShadowEffect* MainWindow::CreateShadow(){
    QGraphicsDropShadowEffect *DropShadowEffect = new QGraphicsDropShadowEffect();

    DropShadowEffect->setBlurRadius(4);
    DropShadowEffect->setColor(QColor(0, 0, 0, 25));
    DropShadowEffect->setOffset(0, 4);
    return DropShadowEffect;
}



