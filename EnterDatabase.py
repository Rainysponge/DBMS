import os
import csv
from tkinter.messagebox import showinfo


# 解决方法如下，将使用的数据库名写入到某一个文件中，每次enter_database时都进行修改。
def enter_database(txt):
    # print(database_name)
    exists = False
    try:
        # with open xxx  先看看有没有这个数据库再进入
        with open('database.csv', 'r+', newline='') as f:
            database_list = csv.reader(f)
            if database_list:
                for item in database_list:
                    # print(''.join(item))
                    if txt == ''.join(item):
                        exists = True
        if exists:
            with open('database_use.txt', 'w+', newline='') as f:
                f.write(txt)
            path = os.getcwd() + '\\' + txt
            showinfo("感谢使用", '<database:'+txt+'>正在被使用！')
        else:
            showinfo("ERROR", '没有该数据库')

        # os.chdir(path)
    except Exception as e:
        showinfo("ERROR", e)
    else:
        print(txt)
