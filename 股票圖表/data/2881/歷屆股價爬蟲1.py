import wget
import time

a=input("股票(3035):")
b=int(input("開始年(2020):"))
b1=int(input("開始月(01):"))
c=int(input("結束年(2022):"))
c1=int(input("結束月(05):"))

d=b
e=b1
for i in range((c-b)*12-b1+c1+1):
    if(e<10):
        f=("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+str(d)+"0"+str(e)+"01&stockNo="+a)
    else:
        f=("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+str(d)+""+str(e)+"01&stockNo="+a)
    wget.download(f)
    if(e==12):
        d=d+1
        e=e-12
    e=e+1
    time.sleep(3)
