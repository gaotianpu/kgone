#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys
sys.path.append("..")
import random

from BeautifulSoup import BeautifulSoup

import browser 
from config import download_dir,htmlCharset
from util import completeInnerUrl,save_file,load_proxies

def download_mtheater_list(page_index=1,proxy=None): 
    url = "http://bj.nuomi.com/cinema/0-0/subd/cb0-d10000-s0-o-b1-f0?pn=%d" % (page_index)
    lfile = '%snuomi/mtheater_list_%d.html' % (download_dir,page_index) 

    respHtml = browser.downad_and_save(url,lfile,proxy)  
    soup = BeautifulSoup(respHtml, fromEncoding=htmlCharset)

    li = []
    dom_mtheaters = soup.findAll('h3',attrs = {'class': 'cib-name'})
    for mt in dom_mtheaters:
        dom_a = mt.find('a')
        uid = dom_a['href'].split('/')[-1]
        uri = completeInnerUrl("http://bj.nuomi.com/",dom_a['href'])
        name = dom_a.contents[0]
        li.append("MovieTheater,北京,%s,%s,%s"%(uid,uri,name))   
    
    csv_file = '%snuomi/mtheater_result_%d.csv' % (download_dir,page_index) 
    save_file(csv_file,li)

def download_mtheater_list_m(page_index=1,proxy=None):
    pass
    # http://m.dianying.baidu.com/?sfrom=newnuomi&source=nuomi&c=131&sub_channel=nuomi_wap_rukou1&isajax=1&pageSize=10&pageNum=0 

def mtheater_all():
    proxies = load_proxies()
    for i in range(1,9):
        try:
            # proxy = random.choice(proxies).strip()
            download_mtheater_list(i)
        except Exception,e:
            print i,'err',e

    os.system('rm -f %snuomi/mtheater.csv'%(download_dir))
    os.system('cat %snuomi/mtheater_result_* >> %snuomi/mtheater.csv' % (download_dir,download_dir) )

def download_movie_playing():
    url = "http://bj.nuomi.com/movie/" 
    lfile = '%snuomi/movies_playing.html' % (download_dir) 

    respHtml = browser.downad_and_save(url,lfile)  
    soup = BeautifulSoup(respHtml, fromEncoding=htmlCharset)

    li = []
    # <div class="section-item clearfix no-top-border">
    dom_movies = soup.find('div',attrs = {'class': 'section-item clearfix no-top-border'})
    dom_a = dom_movies.findAll('a')
    for m in dom_a:
        # dom_a = m.find('a')
        uid = m['href'].split('/')[-1]
        uri = completeInnerUrl("http://bj.nuomi.com/",m['href'])
        name = m.contents[0]
        li.append("Movie,%s,%s,%s"%(uid,uri,name))   
    
    csv_file = '%snuomi/movie_result.csv' % (download_dir) 
    save_file(csv_file,li)


def download_price(theater_id,movie_id):
    # http://bj.nuomi.com/pcindex/main/timetable?cinemaid=1c2e250a3e9691059ee32187&mid=9762&needMovieInfo=0&tploption=5&_=1448004690864#j-movie-list1
    url = "http://bj.nuomi.com/pcindex/main/timetable?cinemaid=%s&mid=%s&needMovieInfo=0"%(theater_id,movie_id)
    lfile = '%snuomi/price_%s_%s.html' % (download_dir,theater_id,movie_id) 
    respHtml = browser.downad_and_save(url,lfile)  
    soup = BeautifulSoup(respHtml, fromEncoding=htmlCharset)

    li = []
    dom_divs = soup.findAll('div',attrs = {'class': 'list'})
    for day,div in enumerate(dom_divs):        
        trs = div.findAll('tr')        
        rows = []
        for tr in trs: 
            tds = tr.findAll('td') 
            
            if not tds: continue

            p = tds[3].find('span')
            pp = p.contents[0].split(';')[-1]
            order_url = completeInnerUrl("http://bj.nuomi.com/", tds[4].find('a')['href']) 

            li.append(','.join([str(day),theater_id,movie_id,tds[0].contents[0].strip(),tds[1].contents[0],pp.strip(),order_url]))
          

        csv_file = '%snuomi/price_%s_%s.csv' % (download_dir,theater_id,movie_id) 
        save_file(csv_file,li) 


if __name__ == "__main__":
    # download_price('1c2e250a3e9691059ee32187','9762')
    # download_movie_playing()
    mtheater_all()
    # download_mtheater_list()

