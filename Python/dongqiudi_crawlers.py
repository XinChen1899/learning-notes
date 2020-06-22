import requests
from lxml import etree
import csv

open("2019-20赛季欧洲五大联赛积分榜.csv",'wt')

for k in range(1, 11):
    if k <= 4 or k == 10:
        header = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Safari/537.36"}
        web = "https://www.dongqiudi.com/data/"+str(k)
        res = requests.get(web,headers=header)
        print(res)


        selector = etree.HTML(res.text)
        p = selector.xpath('//*[@id="__layout"]/div/div[2]/div/div/div/div[2]/div[2]/div[2]/div/div/div/div/p/span/text()')
        print(p)


        row = []
        with open('2019-20赛季欧洲五大联赛积分榜.csv','at',newline = '')as f:
            csvwrite = csv.writer(f)
            if k != 1:
                csvwrite.writerow([' '])
            csvwrite.writerow(p)
            for i in range(1, 21):
                row = []
                for j in range(1, 11):
                    if j == 2:
                        t = selector.xpath('//*[@id="__layout"]/div/div[2]/div/div/div/div[2]/div[2]/div[2]/div/div/div/div/div/p['+str(i)+']/span/b/text()')
                    else:
                        t = selector.xpath('//*[@id="__layout"]/div/div[2]/div/div/div/div[2]/div[2]/div[2]/div/div/div/div/div/p['+str(i)+']/span['+str(j)+']/text()')
                    row = row + t
                print(row)
                csvwrite.writerow(row)





        

