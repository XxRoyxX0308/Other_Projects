import wget
import os
import time
import glob
import ssl

ssl._create_default_https_context = ssl._create_unverified_context

aa=time.localtime(time.time())
b=str(aa[0])
a=str(aa[1])

if(int(a)<10):
    a='0'+a

for i in range(0,10000):
    market= "0" * (4-len(str(i))) + str(i)
    if([]!=glob.glob(r'data/'+market+'/*')):
        for j in range(2020,int(b)):
            for k in range(1,13):
                if(k<10):
                    if([]==glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+str(j)+'0'+str(k)+'.csv')):
                        wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+str(j)+'0'+str(k)+"01&stockNo="+market,"data/"+market)
                        time.sleep(3)
                else:
                    if([]==glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+str(j)+str(k)+'.csv')):
                        wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+str(j)+str(k)+"01&stockNo="+market,"data/"+market)
                        time.sleep(3)

        for k in range(1,int(a)+1):
            if(k<10):
                if([]==glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+'0'+str(k)+'.csv')):
                    wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+b+'0'+str(k)+"01&stockNo="+market,"data/"+market)
                    time.sleep(3)
            else:
                if([]==glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+str(k)+'.csv')):
                    wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+b+str(k)+"01&stockNo="+market,"data/"+market)
                    time.sleep(3)
       
        if([]!=glob.glob(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+a+'.csv')):
            os.remove(r'data/'+market+'\STOCK_DAY_'+market+'_'+b+a+'.csv')
            wget.download("https://www.twse.com.tw/exchangeReport/STOCK_DAY?response=csv&date="+b+a+"01&stockNo="+market,"data/"+market)
            time.sleep(3)
