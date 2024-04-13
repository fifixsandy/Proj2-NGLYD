#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QRegularExpressionValidator>



#define DEBUG



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void NumPressed();

private:
    QGraphicsDropShadowEffect* CreateShadow();
    Ui::MainWindow *ui;
    int InitButtons();
    void AddShadowToButtons();
    void ConfDisplay();
};
#endif // MAINWINDOW_H
