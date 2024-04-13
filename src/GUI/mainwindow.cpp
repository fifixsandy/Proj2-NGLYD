#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AddShadowToButtons();
    ConfDisplay();
    InitButtons();
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

int MainWindow::InitButtons(){

    QPushButton *NumButtons[10];
    for(int i = 0; i < 10; ++i){
        QString ButName = "Button" + QString::number(i);

        NumButtons[i] = MainWindow::findChild<QPushButton *>(ButName);

        connect(NumButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }
    return 1;
}

void MainWindow::NumPressed(){
    QPushButton *Button = (QPushButton *)sender();

    QString ButtonVal = Button->text();

    ui->Display->insert(ButtonVal);
}
