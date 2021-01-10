#ifndef CHANGETABLEWINDOW_H
#define CHANGETABLEWINDOW_H

#include <QDialog>

namespace Ui {
class changeTableWindow;
}

class changeTableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit changeTableWindow(QWidget *parent = nullptr);
    ~changeTableWindow();

private:
    Ui::changeTableWindow *ui;
};

#endif // CHANGETABLEWINDOW_H
