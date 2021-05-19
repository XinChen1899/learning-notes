# 编码格式 : UTF-8
# 开发人员 : 陈昕
# 开发时间 : 2021/5/4 9:21
# 文件名称 : main.py
# 开发工具 : PyCharm

import tkinter as tk
import train
from tkinter import ttk
from tkinter import messagebox, Label
import city
import xlwt
import xlrd
from xlutils3.copy import copy

wbk = xlwt.Workbook()
sheet = wbk.add_sheet('my ticket info')
sheet.write(0, 0, '车次')
sheet.write(0, 1, '出发站')
sheet.write(0, 2, '到达站')
sheet.write(0, 3, '出发时间')
sheet.write(0, 4, '到达时间')
sheet.write(0, 5, '票席')
wbk.save("my ticket.xls")

window = tk.Tk()

window.title("12306破产订票系统")
window.resizable(height=False, width=False)

window.geometry("1000x450")

label1 = Label(window, text="出发地")
label2 = Label(window, text="目的地")
label3 = Label(window, text="出发时间")

e1 = tk.Entry(window, font=('Arial', 14))
e2 = tk.Entry(window, font=('Arial', 14))
e3 = tk.Entry(window, font=('Arial', 14))

label1.grid(row=0)
label2.grid(row=1)
label3.grid(row=2)

e1.grid(row=0, column=1, pady=5)
e2.grid(row=1, column=1, pady=5)
e3.grid(row=2, column=1, pady=5)

reserveInfo = []
comboxText = tk.StringVar()

def deleleTree(tree):
    x = tree.get_children()
    for item in x:
        tree.delete(item)


def query():
    deleleTree(tree)
    from_station = e1.get().strip()
    to_station = e2.get().strip()
    if (city.getCityCode(from_station) is None):
        messagebox.askokcancel('提示', '出发地输入错误')
        return
    if (city.getCityCode(to_station) is None):
        messagebox.askokcancel('提示', '目的地输入错误')
        return

    train_date = e3.get().strip()
    trainList = []
    print(type(trainList))
    try:
        trainList = train.getTrain(from_station, to_station, train_date)
    except Exception as e:
        messagebox.askokcancel("提示", "查询超时，请稍后再试")
        raise e

    for i in range(0, len(trainList)):
        tree.insert("", i, values=trainList[i])

def getItem(event):
    global reserveInfo
    global comboxText
    ticketList = []
    cur_item = tree.focus()
    infoList = tree.item(cur_item)['values']
    reserveInfo = infoList[0:5]
    for i in range(5, 12):
        if len(infoList[i]) != 0:
            if i == 5:
                infoList[i] = '商务座'
            elif i == 6:
                infoList[i] = '一等座'
            elif i == 7:
                infoList[i] = '二等座'
            elif i == 8:
                infoList[i] = '软卧'
            elif i == 9:
                infoList[i] = '硬卧'
            elif i == 10:
                infoList[i] = '硬座'
            elif i == 11:
                infoList[i] = '无座'
            ticketList.append(infoList[i])
    ticketComboxList = ttk.Combobox(window, textvariable=comboxText)
    ticketComboxList['values'] = (ticketList)
    ticketComboxList.current(0)
    ticketComboxList.grid(row=3, column=9, pady=10)
    reserveButton = tk.Button(window, text='预定', command=reserve)
    reserveButton.grid(row=3, column=10, pady=10)

def reserve():
    global reserveInfo
    reserveInfo.append(comboxText.get())
    workbook = xlrd.open_workbook(r'my ticket.xls')
    sheets = workbook.sheet_names()  # 获取工作簿中的所有表格
    worksheet = workbook.sheet_by_name(sheets[0])  # 获取工作簿中所有表格中的的第一个表格
    rows_old = worksheet.nrows  # 获取表格中已存在的数据的行数
    new_workbook = copy(workbook)  # 将xlrd对象拷贝转化为xlwt对象
    new_worksheet = new_workbook.get_sheet(0)  # 获取转化后工作簿中的第一个表格
    new_worksheet.write(rows_old, 0, reserveInfo[0])
    new_worksheet.write(rows_old, 1, reserveInfo[1])
    new_worksheet.write(rows_old, 2, reserveInfo[2])
    new_worksheet.write(rows_old, 3, reserveInfo[3])
    new_worksheet.write(rows_old, 4, reserveInfo[4])
    new_worksheet.write(rows_old, 5, reserveInfo[5])
    new_workbook.save("my ticket.xls")
    print('写入成功')

queryButton = tk.Button(window, text='点我查询', command=query)
queryButton.grid(row=3, column=8, pady=10)

tree = ttk.Treeview(window, show="headings")
tree['columns'] = ("车次", "出发站", "到达站", "出发时间", "到达时间", "商务座", "一等座", "二等座", "软卧", "硬卧", "硬座", "无座")
width = 80
tree.column("车次", width=width)
tree.column("出发站", width=width)
tree.column("到达站", width=width)
tree.column("出发时间", width=width)
tree.column("到达时间", width=width)
tree.column("商务座", width=width)
tree.column("一等座", width=width)
tree.column("二等座", width=width)
tree.column("硬座", width=width)
tree.column("无座", width=width)
tree.column("软卧", width=width)
tree.column("硬卧", width=width)

for name in tree['columns']:
    tree.heading(name, text=name)

tree.grid(row=5, columnspan=20)
tree.bind("<<TreeviewSelect>>", getItem)

window.mainloop()