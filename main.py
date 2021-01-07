# -*- coding: utf-8 -*-
"""
Created on Tue Jan  5 14:23:19 2021

@author: 37536
"""
import os
import tkinter
from tkinter import ttk
from tkinter.messagebox import showinfo
from tkinter.messagebox import askyesno
from EnterDatabase import enter_database
from CreateDatabase import create_database_tk
from CreateTable import create_table


# database_name = ''

def closeWin():
    anser = askyesno(title='感谢使用', message='Close the window?')
    if anser:
        with open('database_use.txt', 'w+') as f:
            f.write('')
        dbms.destroy()
    else:
        return


def show_database_use():
    with open('database_use.txt', 'r+') as f:
        database_use = f.read()
    if database_use:
        showinfo('正在使用的数据库', '<database:' + database_use + '>')
    else:
        showinfo('Warning', '暂无数据库被使用！')


def funcPass():
    print('被调用了')


def funcT(a):
    print(a)


if __name__ == '__main__':
    dbms = tkinter.Tk()
    # 主窗体命名为dbms
    dbms.geometry('800x600')
    dbms.title('DBMS')

    # L1 = tkinter.Label(dbms, text='用户名')
    # tmp = 1
    buttonForLogin = tkinter.Button(dbms, text="登录", width=15, height=3, command=funcPass)
    # command=lambda : funcT(tmp) 通过该方式传递参数
    buttonForLogin.place(x=10, y=10)

    buttonForRegister = tkinter.Button(dbms, text="注册", width=15, height=3, command=funcPass)
    buttonForRegister.place(x=150, y=10)

    buttonForSQL = tkinter.Button(dbms, text="建立查询", width=15, height=3, command=funcPass)
    buttonForSQL.place(x=290, y=10)

    buttonForCreateDB = tkinter.Button(dbms, text="创建数据库", width=15, height=3, command=create_database_tk)
    buttonForCreateDB.place(x=430, y=10)

    buttonForShowDatabase = tkinter.Button(dbms, text="正在使用的数据库", width=15, height=3, command=show_database_use)
    buttonForShowDatabase.place(x=570, y=10)

    labelForEntryDB = tkinter.Label(dbms, text='想进入的数据库名：')
    labelForEntryDB.place(x=10, y=115)

    entryForEnterDB = tkinter.Entry(dbms, bd=5, font=12, width=25)
    entryForEnterDB.place(x=150, y=115)

    buttonForEnterDB = tkinter.Button(dbms, text="使用该数据库", width=15, height=3,
                                      command=lambda: enter_database(txt=entryForEnterDB.get()))
    buttonForEnterDB.place(x=430, y=100)

    buttonForCreateTable = tkinter.Button(dbms, text="创建表", width=15, height=3, command=create_table)
    buttonForCreateTable.place(x=570, y=100)



    table = ttk.Treeview(dbms)

    table["columns"] = ("姓名", "年龄", "身高", "体重", 'test')  # #定义列
    table.column("姓名", width=100)  # #设置列
    table.column("年龄", width=100)
    table.column("身高", width=100)
    table.column("体重", width=100)
    table.column('test', width=100)
    table.heading("姓名", text="x姓名")  # #设置显示的表头名
    table.heading("年龄", text="x年龄")
    table.heading("身高", text="x身高")
    table.heading("体重", text="x体重")
    table.heading("test", text="xtest")
    table.insert("", 0, text="1", values=("卡恩", "18", "180", "65", 'Null'))  # #给第0行添加数据，索引值可重复
    table.insert("", 1, text="2", values=("范冰冰", "38", "170", "55"))
    table.insert("", 2, text="3", values=("戚薇", "28", "169", "50"))
    table.insert("", 3, text="4", values=("杨霞", "30", "172", "63"))
    table.insert("", 4, text="5", values=("李小冉", "31", "175", "65"))
    table.insert("", 5, text="6", values=("迪丽热巴", "29", "175", "61"))

    table.place(x=10, y=190)
    dbms.protocol('WM_DELETE_WINDOW', closeWin)
    dbms.mainloop()
