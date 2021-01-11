#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class regWindow;
}

class regWindow : public QDialog
{
    Q_OBJECT

public:
    explicit regWindow(QWidget *parent = nullptr);
    ~regWindow();

private slots:
    void on_commitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::regWindow *ui;
};

#endif // REGWINDOW_H
