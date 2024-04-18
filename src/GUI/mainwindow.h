#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QRegularExpressionValidator>
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>

#include "../LIBS/math_operations.h"


#define DEBUG

#define DISPLAY_FONT_SIZE 40
#define DISPLAY_START_LEN 10
#define DISPLAY_MAX_LEN 15



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const QString MatButtons[];
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void NumPressed();
    void CePressed();
    void DotPressed();
    void MatButPressed();
    void HelpPressed();
    void OnTextChanged(const QString &text);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:

    QGraphicsDropShadowEffect* CreateShadow();

    void BinOperations(QString ButtonName, double &AOperand, QString BOperand, bool &CovnersionCheck, MathErrorCode &MathErr);
    void UnOperations(QString ButtonName, QString AOperand, double &Result, bool &CovnersionCheck, MathErrorCode &MathErr);
    void SetNumberToDisplay(double Number, QLineEdit *Display);
    void PrintError();
    void AddShadowToButtons();
    void ConfDisplay();
    bool IsDouble(unsigned long long Var);
    int InitButtons();

    Ui::MainWindow *ui;
    QPushButton *LastPressedButton;
    MathOps Math;
    double CalVarDouble;
    bool Error;

};
#endif // MAINWINDOW_H
