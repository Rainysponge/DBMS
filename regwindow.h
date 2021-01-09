#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QDialog>

namespace Ui {
class regWindow;
}

class regWindow : public QDialog
{
    Q_OBJECT

public:
    explicit regWindow(QWidget *parent = nullptr);
    ~regWindow();

private:
    Ui::regWindow *ui;
};

#endif // REGWINDOW_H
