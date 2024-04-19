/**
 * @file helpwindow.cpp
 *
 * @brief Header file for the HelpWindow class.
 *
 * This file declares the HelpWindow class, which represents a dialog window
 * containing help information. It provides a way to display help content to
 * the user.
 *
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
 */


#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}
