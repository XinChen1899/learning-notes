# 编码格式 : UTF-8
# 开发人员 : 陈昕
# 开发时间 : 2021/5/4 9:20
# 文件名称 : train.py
# 开发工具 : PyCharm
# 爬取车次信息

import requests
import json
import price
import city

def getTrain(from_station, to_station, train_date):
    # url请求参数
    from_station_code = city.getCityCode(from_station)
    to_station_code = city.getCityCode(to_station)
    if(from_station_code is None):
        print("出发地错误")
        return []
    if(to_station_code is None):
        print("目的地错误")
        return []
    from_station_param = from_station + ',' + from_station_code
    to_station_param = to_station + ',' + to_station_code
    date_param = train_date

    header = {
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "zh-CN,zh;q=0.9",
        "Cache-Control": "max-age=0",
        "Connection": "keep-alive",
        "Cookie": '''JSESSIONID=19244E64B10E57EFB354E317CC0DD2C5; BIGipServerotn=535822858.50210.0000; RAIL_EXPIRATION=1582333451491; RAIL_DEVICEID=McIuEPF2UftrVKz1eNePew8hyOmYixP1IVU1JOTtULuRy2igIY3K71OCqb2YQni1FEkLyWbxf508zd6v91pHbnHRZ2UU0SLJBBsbittDazpLO-ZB7zoirqGyH9ao0cAv_d76BNGKrAVsosQuv0EkQuOczvUHWMcx; BIGipServerpool_passport=317522442.50215.0000; route=9036359bb8a8a461c164a04f8f50b252; _jc_save_toStation=%u4E0A%u6D77%2CSHH; _jc_save_wfdc_flag=dc; _jc_save_fromStation=%u957F%u6C99%2CCSQ; _jc_save_fromDate=2020-02-19; _jc_save_toDate=2020-02-19''',
        "Host": "kyfw.12306.cn",
        "sec-ch-ua": "\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"90\", \"Google Chrome\";v=\"90\"",
        "sec-ch-ua-mobile": "?0",
        "Sec-Fetch-Dest": "document",
        "Sec-Fetch-Mode": "navigate",
        "Sec-Fetch-Site": "none",
        "Sec-Fetch-User": "?1",
        "Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36",
    }

    url = 'https://kyfw.12306.cn/otn/leftTicket/query?leftTicketDTO.train_date={}&leftTicketDTO.from_station={}&leftTicketDTO.to_station={}&purpose_codes=ADULT'.format(train_date, from_station_code, to_station_code)

    response = requests.get(url = url, headers = header, verify=False)
    response.encoding = "utf-8"
    if(response.content):
        response = response.content.decode('utf-8')

        # text包含BOM字符 需要去掉，否则有时报错
        if response.startswith(u'\ufeff'):
            response = response.encode('utf8')[3:].decode('utf8')

        dictInfo = json.loads(response)

        trainList = dictInfo['data']['result']

        result = []
        for i in trainList:
            list = i.split("|")
            checi = list[3]
            chufa = city.getCityName(list[6])
            mudi = city.getCityName(list[7])
            ftime = list[8]
            dtime = list[9]
            prices = price.getPrice(list[39])
            sw = list[32] + prices['sw']  # 商务
            yd = list[31] + prices['yd']  # 一等
            ed = list[30] + prices['ed']  # 二等
            rw = list[23] + prices['rw']  # 软卧
            yw = list[28] + prices['yw']  # 硬卧
            yz = list[29] + prices['yz']  # 硬座
            wz = list[26] + prices['wz']  # 无座
            result.append((checi,chufa,mudi,ftime,dtime,sw,yd,ed,rw,yw,yz,wz))
        return result



if __name__ == "__main__":

    list = getTrain('长沙', '拉萨', '2021-05-08')
    for item in list:
        print(item)