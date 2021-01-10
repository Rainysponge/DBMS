#ifndef CREATETABLE_H
#define CREATETABLE_H

#include <QDialog>
#include <QComboBox>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class createTable;
}

class createTable : public QDialog
{
    Q_OBJECT

public:
    explicit createTable(QWidget *parent = nullptr);
    ~createTable();

public slots:
    void print_Type();



private slots:
    void on_pushButtonCreate_clicked();

    void on_pushButtonAddCon_clicked();

//    void on_pushButtonChange_clicked();

private:
    Ui::createTable *ui;
};

#endif // CREATETABLE_H
