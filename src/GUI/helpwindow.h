/**
 * @file helpwindow.h
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

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui {
class HelpWindow;
}

/**
 * @class HelpWindow
 * @brief The HelpWindow class represents a dialog window for displaying help information.
 */
class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for HelpWindow.
     * @param parent The parent widget.
     */
    explicit HelpWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for HelpWindow.
     */
    ~HelpWindow();

private:
    Ui::HelpWindow *ui; /**< Pointer to the UI object. */
};

#endif // HELPWINDOW_H
