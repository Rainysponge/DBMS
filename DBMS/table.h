#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    ~table();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_S_clicked();

private:
    Ui::table *ui;
    QVector<QString> x;//存储csv文件第1列数据
    QVector<QVector<QString>> qv2;
    int col;
    QStringList list1;
    QString filename;
};

#endif // TABLE_H
