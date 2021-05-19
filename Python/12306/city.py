# 编码格式 : UTF-8
# 开发人员 : 陈昕
# 开发时间 : 2021/5/4 9:19
# 文件名称 : city.py
# 开发工具 : PyCharm
# 功能: 获取12306城市码

import requests
import re

cities = None

# 爬取12306全部城市码（用来组成爬取车次时的url），并组织成字典
def createCityDict():
    global cities
    if (cities is None):
        requests.packages.urllib3.disable_warnings()
        url = 'https://kyfw.12306.cn/otn/resources/js/framework/station_name.js?station_version=1.9050'
        r = requests.get(url, verify=False)  # 提取网页信息，不判断证书
        pattern = u'([\u4e00-\u9fa5]+)\|([A-Z]+)'  # 正则表达式提取中文以及大写英文字母
        result = re.findall(pattern, r.text)
        cities = dict(result)
    return cities


# 根据城市代码，返回城市名称
def getCityName(code):
    station = createCityDict()
    for city_name, city_code in station.items():
        if (city_code == code):
            return city_name
    return None


# 根据城市名称，返回12306城市代码
def getCityCode(name):
    station = createCityDict()
    for city_name, city_code in station.items():
        if (city_name == name):
            return city_code
    return None

if __name__ == '__main__':
    print(getCityCode('娄底'))
    print(getCityName('WHN'))