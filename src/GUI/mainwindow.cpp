/**
 * @file mainwindow.cpp
 *
 * @brief Implementation file for the MainWindow class.
 *
 * This file contains the implementations of member functions of the MainWindow class,
 * which represents the main window of the application. It includes functions for handling
 * button presses, performing mathematical operations, configuring the display, and managing
 * event filtering.
 *
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
 */


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "helpwindow.h"


const QString MainWindow::MatButtons[] = {
    QStringLiteral("ButtonAdd"),
    QStringLiteral("ButtonSub"),
    QStringLiteral("ButtonMod"),
    QStringLiteral("ButtonRoot"),
    QStringLiteral("ButtonSquareRoot"),
    QStringLiteral("ButtonDiv"),
    QStringLiteral("ButtonMul"),
    QStringLiteral("ButtonFact"),
    QStringLiteral("ButtonPower"),
    QStringLiteral("ButtonEqual")
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add drop shadow effects to buttons
    AddShadowToButtons();

    // Configure the display with a regular expression validator
    ConfDisplay();

    // Initialize button connections
    InitButtons();

    // Initialize variables
    Error = false;
    CalVarDouble = 0;
    LastPressedButton = nullptr;

    // Connect signals and slots
    connect(ui->Display, &QLineEdit::textChanged, this, &MainWindow::OnTextChanged);
    ui->Display->installEventFilter(this);
    ui->Display->setFocus();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        // Handle key events for Enter, Asterisk, Slash, Minus, and Plus keys
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            ui->ButtonEqual->click();
            event->accept();
        }
        else if(keyEvent->key() == Qt::Key_Asterisk){
            ui->ButtonMul->click();
            event->accept();
        }
        else if(keyEvent->key() == Qt::Key_Slash){
            ui->ButtonDiv->click();
            event->accept();
        }
        else if(keyEvent->key() == Qt::Key_Minus){
            ui->ButtonSub->click();
            event->accept();
        }
        else if(keyEvent->key() == Qt::Key_Plus){
            ui->ButtonAdd->click();
            event->accept();
        }
        else{
            return QObject::eventFilter(obj, event);
        }
        return true;
    }
    return QObject::eventFilter(obj, event);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConfDisplay(){
    // Configure the display with a regular expression validator for numeric input
    QRegularExpression rx("[0-9]+[.]{0,1}[0-9]*");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->Display->setValidator(validator);
}

void MainWindow::AddShadowToButtons(){
    // Add drop shadow effects to all buttons
    QList<QPushButton *> Buttons = MainWindow::findChildren<QPushButton *>();
    for (auto but: Buttons){
        but->setGraphicsEffect(CreateShadow());
    }
}

QGraphicsDropShadowEffect* MainWindow::CreateShadow(){
    // Create a drop shadow effect with specific properties
    QGraphicsDropShadowEffect *DropShadowEffect = new QGraphicsDropShadowEffect();
    DropShadowEffect->setBlurRadius(4);
    DropShadowEffect->setColor(QColor(0, 0, 0, 25));
    DropShadowEffect->setOffset(0, 4);
    return DropShadowEffect;
}

int MainWindow::InitButtons(){
    // Initialize connections for numeric buttons
    QPushButton *NumButtons[10];
    for(int i = 0; i < 10; ++i){
        QString ButName = "Button" + QString::number(i);
        NumButtons[i] = MainWindow::findChild<QPushButton *>(ButName);
        connect(NumButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    // Initialize connections for CE and Help buttons
    QString ButName = "ButtonCe";
    connect(MainWindow::findChild<QPushButton *>(ButName), SIGNAL(released()), this, SLOT(CePressed()));

    ButName = "ButtonHelp";
    connect(MainWindow::findChild<QPushButton *>(ButName), SIGNAL(released()), this, SLOT(HelpPressed()));

    ButName = "ButtonDot";
    connect(MainWindow::findChild<QPushButton *>(ButName), SIGNAL(released()), this, SLOT(DotPressed()));

    // Initialize connections for mathematical operation buttons
    for(auto i:MatButtons){
        connect(MainWindow::findChild<QPushButton *>(i), SIGNAL(released()), this,
                SLOT(MatButPressed()));
    }

    return 1;
}

void MainWindow::HelpPressed(){
    // Display the help window
    HelpWindow help;
    help.show();
    help.exec();
}

void MainWindow::CePressed(){
    // Clear the display and reset variables
    ui->Display->clear();
    ui->Display2->clear();
    Error = false;
    LastPressedButton = nullptr;
    CalVarDouble = 0;
}

void MainWindow::DotPressed(){
    // Insert a dot into the display
    ui->Display->insert(".");
}

void MainWindow::MatButPressed(){
    if(Error) return;

    bool ConversionCheck;
    MathErrorCode MathErr = SUCCESS;

    // Handle mathematical operation button press
    QPushButton *Button = (QPushButton *)sender();
    QString text = ui->Display->text();

    if(LastPressedButton == nullptr){
        QString ButtonName = Button->objectName();

        if(text.isEmpty()){
            if(ButtonName == "ButtonSub"){
                ui->Display->setText("-");
            }
            return;
        }
        if(ButtonName == "ButtonFact" || ButtonName == "ButtonSquareRoot"){
            UnOperations(ButtonName, text, CalVarDouble, ConversionCheck, MathErr);
            SetNumberToDisplay(CalVarDouble, ui->Display);
        }
        else{

            CalVarDouble = text.toDouble(&ConversionCheck);
            LastPressedButton = Button;
            SetNumberToDisplay(CalVarDouble, ui->Display2);
            ui->Display->clear();
        }
    }
    else{
        BinOperations(LastPressedButton->objectName(), CalVarDouble, text,
                      ConversionCheck, MathErr);

        SetNumberToDisplay(CalVarDouble, ui->Display);
        LastPressedButton = Button;
        SetNumberToDisplay(CalVarDouble, ui->Display2);
        if(Button->objectName() != "ButtonEqual") ui->Display->clear();
    }

    if(!ConversionCheck || MathErr != SUCCESS) PrintError();
    if(Button->objectName() == "ButtonEqual"){
        LastPressedButton = nullptr;
        ui->Display2->clear();
      }
}

void MainWindow::NumPressed(){
    // Handle numeric button press
    QPushButton *Button = (QPushButton *)sender();
    QString ButtonVal = Button->text();
    ui->Display->insert(ButtonVal);
}

bool MainWindow::IsDouble(unsigned long long Var){
    // Check if a number is a double
    return Var == static_cast<unsigned long long>(static_cast<double>(Var));
}

void MainWindow::PrintError(){
    // Display an error message on the display
    Error = true;
    ui->Display->setText("ERROR");
}

void MainWindow::BinOperations(QString ButtonName, double &AOperand, QString BOperand, bool &ConversionCheck, MathErrorCode &MathErr){
    // Perform binary mathematical operations
    if(ButtonName == "ButtonAdd"){
        AOperand = Math.add(AOperand, BOperand.toDouble(&ConversionCheck));
    }
    else if(ButtonName == "ButtonSub"){
        AOperand = Math.subtract(AOperand, BOperand.toDouble(&ConversionCheck));
    }
    else if(ButtonName == "ButtonMod"){
        AOperand = Math.modulo(AOperand, BOperand.toDouble(&ConversionCheck), MathErr);
    }
    else if(ButtonName == "ButtonRoot"){
        AOperand = Math.nthRoot(AOperand, BOperand.toInt(&ConversionCheck), MathErr);
    }
    else if(ButtonName == "ButtonDiv"){
        AOperand = Math.divide(AOperand, BOperand.toDouble(&ConversionCheck), MathErr);
    }
    else if(ButtonName == "ButtonMul"){
        AOperand = Math.multiply(AOperand, BOperand.toDouble(&ConversionCheck));
    }
    else if(ButtonName == "ButtonPower"){
        AOperand = Math.nthPower(AOperand, BOperand.toInt(&ConversionCheck));
    }
}

void MainWindow::UnOperations(QString ButtonName, QString AOperand, double &Result, bool &ConversionCheck, MathErrorCode &MathErr){
    // Perform unary mathematical operations
    if(ButtonName == "ButtonFact"){
        unsigned long long tmp = Math.factorial(AOperand.toInt(&ConversionCheck), MathErr);
        if(!ConversionCheck) return;
        ConversionCheck = IsDouble(tmp);
        Result = static_cast<double>(tmp);
    }
    else if(ButtonName == "ButtonSquareRoot"){
        Result = Math.squareRoot(AOperand.toInt(&ConversionCheck), MathErr);
    }
}

void MainWindow::OnTextChanged(const QString &text){
    // Adjust font size based on the length of the text in the display
    int size = text.length();
    QFont font = ui->Display->font();
    if(size > DISPLAY_START_LEN && size <= DISPLAY_MAX_LEN){
        font.setPointSize(DISPLAY_FONT_SIZE*DISPLAY_START_LEN/size);
        ui->Display->setFont(font);
    }
    else{
        font.setPointSize(DISPLAY_FONT_SIZE);
        ui->Display->setFont(font);
    }
}

void MainWindow::SetNumberToDisplay(double Number, QLineEdit *Display){
    // Set the number to the display, with scientific notation if needed
    int length = QString::number(Number).length();
    if(length > 8) Display->setText(QString::number(Number, 'e', 8));
    else Display->setText(QString::number(Number));
}
