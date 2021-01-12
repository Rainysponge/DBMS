#ifndef CHANGELIMITW_H
#define CHANGELIMITW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class changeLimitW;
}

class changeLimitW : public QDialog
{
    Q_OBJECT

public:
    explicit changeLimitW(QWidget *parent = nullptr);
    ~changeLimitW();

private slots:
    void on_pushButtonShow_clicked();

    void on_pushButtonSummit_clicked();

private:
    Ui::changeLimitW *ui;
};

#endif // CHANGELIMITW_H
