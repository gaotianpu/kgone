# -*- coding: utf-8 -*-
import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule

import urlparse
from lxml.html.clean import Cleaner
import re 

from douban.items import DoubanItem

book_properties = {u'作者':'author',u'出版社':'puborg',u'原作名':'author1',u'译者':'translator',u'出版年':'publish_date',u'页数':'pageCount',u'定价':'price',u'装帧':'zhuangzhen',u'ISBN':'isbn'}


class DoubanBookSpider(CrawlSpider):
    name = 'douban_book'
    allowed_domains = ['douban.com']
    start_urls = ['http://book.douban.com/']

    rules = (
        Rule(LinkExtractor(allow=r'^http://book\.douban\.com/subject/(\d+)/$'), callback='parse_item', follow=True),
    )

    def parse_item(self,response):
        item = DoubanItem()
        m = re.search(r'(\d+)',response.url)
        item['Id']=  m.group(0) if m else '' 
        item['url']= response.url

        func = lambda x : x[0].strip() if len(x)>0 else ''  

        # #wrapper > h1 > span
        item['name']= func(response.css('#wrapper > h1 > span::text').extract())  
        # #mainpic > a > img
        item['image']= func(response.css('#mainpic > a > img::attr(src)').extract()) 

        intro = response.css('#info').extract()  # #info
        if intro:
            intro =  ''.join(''.join(intro[0].splitlines()).split('  ')) #？use reg?
            cleaner = Cleaner(allow_tags=['br'], remove_unknown_tags=False)
            for i in cleaner.clean_html(intro).replace("<div>",'').replace('</div>','').split('<br>'):             
                x = i.split(':') 
                # print x[0],x[1] if len(x)>1 else ''
                if x[0].strip() in book_properties.keys():
                    kk = book_properties[x[0].strip()]
                    print kk
                    item[kk] = x[1] if len(x)>1 else ''
                else:
                    self.logger.info('undfine item %s', i )
                    
        else:
            self.logger.info('#info is null %s', item['Id']) 
               
        # #link-report > div:nth-child(1) > div
        item['bookInfo']= func(response.css('#link-report > div:nth-child(1) > div').extract()) #需要进一步的分拆？
        # #content > div > div.article > div.related_info > div:nth-child(5) > div > div
        item['authorInfo']= func(response.css('div.related_info > div:nth-child(5) > div > div').extract()) #需要进一步的分拆？        
        # #content > div > div.article > div.related_info > div:nth-child(1) > div > div.ebook-link > a
        ebookId = func(response.css('div.ebook-link > a::attr(href)').extract())    #电子书链接 
        item['ebookId']= ebookId.split('?')[0] if  ebookId else ''
        # #db-tags-section > div > span:nth-child(1) > a 
        item['tags']= response.css('#db-tags-section > div > span > a::text').extract()
        # #collector > p:nth-child(7) > a 
        item['wantCount']= response.css('#collector > p:nth-child(7) > a::text').re_first('(\d+)') #.extract()
        # #collector > p:nth-child(6) > a
        item['readCount']= response.css('#collector > p:nth-child(6) > a::text').re_first('(\d+)') #.extract()
        # #collector > p:nth-child(5) > a
        item['readingCount']= response.css('#collector > p:nth-child(5) > a::text').re_first('(\d+)') #.extract()
        # #interest_sectl > div > div.rating_self.clearfix > strong
        item['score']= func(response.css('div.rating_self.clearfix > strong::text').extract())   
        # #interest_sectl > div > div.rating_self.clearfix > div > div.rating_sum > span > a > span
        item['reviewCount']= func(response.css('div.rating_sum > span > a > span::text').extract())   
        # #buyinfo-printed > ul > li > a   #购买连接 
        urls = response.css('#buyinfo-printed > ul > li > a::attr(href)').extract()   
        func = lambda x,key : x[key][0] if x.has_key(key) else ''
        urlss = []
        for url in [func(urlparse.parse_qs(urlparse.urlparse(u).query,True),'url') for u in urls]:
            if url.find('dangdang.com')>-1:
                urlss.append(func(urlparse.parse_qs(urlparse.urlparse(url).query,True),'backurl'))
            elif url.find('winxuan.com')>-1:
                urlss.append(func(urlparse.parse_qs(urlparse.urlparse(url).query,True),'url'))
            # elif url.find('beifabook.com')>-1:
            #     urlss.append(func(urlparse.parse_qs(urlparse.urlparse(u).query,True),'url'))
            elif url.find('bookschina.com')>-1:
                urlss.append(func(urlparse.parse_qs(urlparse.urlparse(url).query,True),'tourl'))
            else:
                urlss.append(url)


        item['otherSites']= urlss # [func(urlparse.parse_qs(urlparse.urlparse(u).query,True)) for u in urls] 

        return item 
