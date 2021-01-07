import os
import csv
import tkinter
from tkinter.messagebox import showinfo


def create_table_tk():
    create_table_root = tkinter.Tk()
    # 主窗体命名为dbms
    create_table_root.geometry('300x300')
    create_table_root.title('创建表')
    create_table_root.mainloop()


def create_table():
    # with 先判断是否有数据库正在被使用
    with open('database_use.txt', 'r+') as f:
        database_use = f.read()
    if database_use:
        # print(database_use)
        create_table_tk()
    else:
        print('请先选择要使用的数据库！')
        showinfo("ERROR", '请先选择要使用的数据库！')
