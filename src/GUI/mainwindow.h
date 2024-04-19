/**
 * @file mainwindow.h
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

/**
 * @file mainwindow.h
 * @brief Header file for the MainWindow class.
 */

/**
 * @class MainWindow
 * @brief The MainWindow class represents the main window of the application.
 */


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Array of names for mathematical operation buttons.
     */
    static const QString MatButtons[];

    /**
     * @brief Constructor for MainWindow.
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot for handling numeric button presses.
     */
    void NumPressed();

    /**
     * @brief Slot for handling CE (clear) button press.
     */
    void CePressed();

    /**
     * @brief Slot for handling dot button press.
     */
    void DotPressed();

    /**
     * @brief Slot for handling mathematical operation button press.
     */
    void MatButPressed();

    /**
     * @brief Slot for handling help button press.
     */
    void HelpPressed();

    /**
     * @brief Slot for handling text changes in the display.
     * @param text The new text in the display.
     */
    void OnTextChanged(const QString &text);

protected:
    /**
     * @brief Event filter function to handle key events.
     * @param obj The object that received the event.
     * @param event The event that occurred.
     * @return True if the event was handled, false otherwise.
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    /**
     * @brief Function to create a drop shadow effect for buttons.
     * @return Pointer to the created drop shadow effect.
     */
    QGraphicsDropShadowEffect* CreateShadow();

    /**
     * @brief Function to perform binary mathematical operations.
     * @param ButtonName The name of the button corresponding to the operation.
     * @param AOperand The first operand.
     * @param BOperand The second operand.
     * @param CovnersionCheck Reference to a boolean variable indicating the success of operand conversion.
     * @param MathErr Reference to a MathErrorCode variable indicating any errors that occurred during the operation.
     */
    void BinOperations(QString ButtonName, double &AOperand, QString BOperand, bool &CovnersionCheck, MathErrorCode &MathErr);

    /**
     * @brief Function to perform unary mathematical operations.
     * @param ButtonName The name of the button corresponding to the operation.
     * @param AOperand The operand.
     * @param Result Reference to the result of the operation.
     * @param CovnersionCheck Reference to a boolean variable indicating the success of operand conversion.
     * @param MathErr Reference to a MathErrorCode variable indicating any errors that occurred during the operation.
     */
    void UnOperations(QString ButtonName, QString AOperand, double &Result, bool &CovnersionCheck, MathErrorCode &MathErr);

    /**
     * @brief Function to set a number to the display.
     * @param Number The number to be displayed.
     * @param Display Pointer to the display widget.
     */
    void SetNumberToDisplay(double Number, QLineEdit *Display);

    /**
     * @brief Function to print an error message on the display.
     */
    void PrintError();

    /**
     * @brief Function to add drop shadow effects to buttons.
     */
    void AddShadowToButtons();

    /**
     * @brief Function to configure the display with a regular expression validator.
     */
    void ConfDisplay();

    /**
     * @brief Function to check if a number is a double.
     * @param Var The number to be checked.
     * @return True if the number is a double, false otherwise.
     */
    bool IsDouble(unsigned long long Var);

    /**
     * @brief Function to initialize button connections.
     * @return 1 if successful, otherwise 0.
     */
    int InitButtons();

    Ui::MainWindow *ui; /**< Pointer to the UI object. */
    QPushButton *LastPressedButton; /**< Pointer to the last pressed button. */
    MathOps Math;   /**< Instance of the MathOps class for mathematical operations. */
    double CalVarDouble;    /**< Variable to hold calculated double values. */
    bool Error; /**< Flag indicating if an error has occurred. */

};
#endif // MAINWINDOW_H
