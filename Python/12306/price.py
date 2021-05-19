# 编码格式 : UTF-8
# 开发人员 : 陈昕
# 开发时间 : 2021/5/7 16:23
# 文件名称 : price.py
# 开发工具 : PyCharm
# 功能 : 解析票价码

price_code1 = 'O022350021M0362500139070600004'
price_code2 = '4020500021301330002110075000211007503000'

def turnIntoNum(str):
    i = 0
    num = 0.0
    for i in range(5):
        num = num*10 + eval(str[i])/10
    return num

def getPrice(code):
    price_list = {'sw':'', 'yd':'', 'ed':'', 'rw':'', 'gjrw':'', 'yw':'', 'yz':'', 'wz':''}  # 商务座，一等座，二等座，软卧，高级软卧，硬卧，硬座，无座
    i = 0
    while(i < (len(code) - 4)):
        price_str = ''
        # 商务座
        if(code[i] == '9'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            price_list['sw'] = '(' + str(turnIntoNum(price_str)) + '元)'
        # 一等座
        elif(code[i] == 'M'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            price_list['yd'] = '(' + str(turnIntoNum(price_str)) + '元)'
        # 二等座
        elif(code[i] == 'O'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            price_list['ed'] = '(' + str(turnIntoNum(price_str)) + '元)'
        # 软卧
        elif(code[i] == '4'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            price_list['rw'] = '(' + str(turnIntoNum(price_str)) + '元)'
        # 高级软卧
        elif(code[i] == '6'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            price_list['gjrw'] = '(' + str(turnIntoNum(price_str)) + '元)'
        # 硬卧
        elif(code[i] == '3'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            price_list['yw'] = '(' + str(turnIntoNum(price_str)) + '元)'
        # 硬座
        elif(code[i] == '1'):
            price_str = code[(i+1):(i+6)]
            i = i + 10
            num = '(' + str(turnIntoNum(price_str)) + '元)'
            price_list['yz'] = num
            price_list['wz'] = num
        else:
            i = i + 1
    return price_list



if __name__ == '__main__':
    print(getPrice(price_code1))
    print(getPrice(price_code2))