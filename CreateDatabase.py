import os
import csv
import tkinter
from tkinter.messagebox import showinfo


def create_dic(root, txt):
    try:
        with open('database.csv', 'a+', newline='') as f:
            writer = csv.writer(f)
            writer.writerows([txt])
        pathDBMSTotal = os.getcwd() + '\\DBMS'
        os.mkdir(pathDBMSTotal + '\\' + txt)
    except Exception as e:
        showinfo("ERROR", e)
        root.destroy()
    else:
        showinfo("Success", '<database:' + txt + '> is created successfully')
        print(txt)
        root.destroy()


def create_database(root, txt):
    # # with open xxxx:
    # # 检查是否有这个数据库的方法  xxx可以是记录数据库名的文件，也可以用os
    # # 以下假装有数据库 a,b,c
    # is_exist = ['a', 'b', 'c']
    exists = False
    with open('database.csv', 'r+', newline='') as f:
        database_list = csv.reader(f)
        if not database_list:
            create_dic(root, txt)
        else:
            for item in database_list:
                # print(''.join(item))
                if txt == ''.join(item):
                    exists = True

    if exists:
        showinfo("ERROR", 'Exists')
        root.destroy()
    else:
        create_dic(root, txt)


def create_database_tk():
    createDB = tkinter.Tk()
    createDB.geometry('500x200')
    createDB.title('createDB')

    labelForEntry = tkinter.Label(createDB, text='想创建的数据库叫：')
    labelForEntry.place(x=210, y=10)

    entryForDBName = tkinter.Entry(createDB, bd=5, font=12, width=35)
    entryForDBName.place(x=90, y=50)

    buttonForCreateDB = tkinter.Button(createDB, text="建立数据库", width=15, height=3
                                       , command=lambda: create_database(root=createDB, txt=entryForDBName.get()))
    buttonForCreateDB.place(x=220, y=90)


def create_dir():
    # 建立目录和进入目录的方法大致如下
    try:
        end = False
        s = input('>')
        print(type(s))

        pathT = os.getcwd()
        print(pathT + '\\' + s)
        os.mkdir(pathT + '\\' + s)  # 创建完成后仍会停留在原来的目录下
        os.chdir(pathT + '\\' + s)
        while (not end):
            s = input('>')
            pathT = os.getcwd()
            print(pathT + '\\' + s)
            os.chdir(pathT + '\\' + s)
    #    os.mkdir(pathT+'\\'+s)
    except Exception as e:
        if isinstance(e, FileExistsError):
            print('exists')
        else:
            print(e)
