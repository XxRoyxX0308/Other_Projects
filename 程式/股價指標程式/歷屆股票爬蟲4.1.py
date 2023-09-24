import wget
import os
import time
import glob
import ssl

ssl._create_default_https_context = ssl._create_unverified_context

b=str(input("年:"))
a=str(input("月:"))

for i in range(0,10000):
    market= "0" * (4-len(str(i))) + str(i)
    if([]!=glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+'0'+a+'.csv')):
        os.remove(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+'0'+a+'.csv')
        wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+b+'0'+a+"01&stockNo="+market,"data/"+market)
        time.sleep(3)
    elif([]!=glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+a+'.csv')):
        os.remove(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+a+'.csv')
        wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+b+a+"01&stockNo="+market,"data/"+market)
        time.sleep(3)
