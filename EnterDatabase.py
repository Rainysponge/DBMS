import os
from tkinter.messagebox import showinfo


def enter_database(txt):
    try:
        # with open xxx  先看看有没有这个数据库再进入

        path = os.getcwd() + '\\' + txt

        os.chdir(path)
    except Exception as e:
        showinfo("ERROR", e)
    else:
        print(txt)

