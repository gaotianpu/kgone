# -*- coding: utf-8 -*-
import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule

import urlparse
from lxml.html.clean import Cleaner
import re 

from douban.items import DoubanItem

book_properties = {u'作者':'author',u'出版社':'publisher',u'副标题':'subtitle',u'丛书':'book_set',u'原作名':'author1',u'译者':'translator',u'出版年':'publish_date',u'页数':'pageCount',u'定价':'price',u'装帧':'zhuangzhen',u'ISBN':'isbn',u'统一书号':'isbn0'}


class DoubanBookSpider(CrawlSpider):
    name = 'douban_book'
    allowed_domains = ['douban.com']
    start_urls = ['http://book.douban.com/tag/']

    # 多个Rule是否有先后顺序？ 
    # LinkExtractor? 
    rules = (
        # Rule(LinkExtractor(deny=r'^http://book\.douban\.com/review/(\d+)/$')),
        # Rule(LinkExtractor(deny=r'^http://movie\.douban\.com/$')),  #如果不定义，url会怎样？

        # (www)[^((?!xyz).)*$] 
        #  deny=r'^http://www\.douban\.com/((?!tag).)*'), 

        Rule(LinkExtractor(allow=r'^http://www\.douban\.com/tag/([^/])*/',process_value=lambda x: x.split('?')[0]), 
            follow=True),
        Rule(LinkExtractor(allow=r'^http://book\.douban\.com/subject/(\d+)/$',process_value=lambda x: x.split('?')[0]), 
            callback='parse_item', follow=True), 
    )

    #not using ?
    # def process_value(self,value):
    #     m = re.search("http://www\.douban\.com/tag/[^/]*/", value)
    #     print value
    #     if m: 
    #         print m.group()
    #         return m.group()
         

    def parse_item(self,response):
        item = DoubanItem()
        
        m = re.search(r'(\d+)',response.url)
        item['Id']=  m.group(0) if m else '' 

        item['url']= response.url 

        # #wrapper > h1 > span
        item['name']= response.css('#wrapper > h1 > span::text').extract_first(default='')  
        # #mainpic > a > img
        item['image']= response.css('#mainpic > a > img::attr(src)').extract_first(default='')  

        intro = response.css('#info').extract()  # #info
        if intro:
            intro =  ''.join(''.join(intro[0].splitlines()).split('  ')) #？use reg?
            cleaner = Cleaner(allow_tags=['br'], remove_unknown_tags=False)
            for i in cleaner.clean_html(intro).replace("<div>",'').replace('</div>','').split('<br>'):             
                x = i.split(':')                  
                if x[0].strip() in book_properties.keys():
                    kk = book_properties[x[0].strip()]                    
                    item[kk] = x[1].strip() if len(x)>1 else ''
                elif not x[0].strip() :
                    pass 
                else:
                    self.logger.warning('undfine item %s,id=%s', i,item['Id']) 
                    
        else:
            self.logger.warning('#info is null %s', item['Id']) 
               
        # #link-report > div:nth-child(1) > div
        item['bookInfo']= response.css('#link-report > div:nth-child(1) > div').extract_first(default='')  #需要进一步的分拆？
        # #content > div > div.article > div.related_info > div:nth-child(5) > div > div
        item['authorInfo']= response.css('div.related_info > div:nth-child(5) > div > div').extract_first(default='')   #需要进一步的分拆？        
        # #content > div > div.article > div.related_info > div:nth-child(1) > div > div.ebook-link > a
        ebookId = response.css('div.ebook-link > a::attr(href)').extract_first(default='')      #电子书链接 
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
        item['score']= response.css('div.rating_self.clearfix > strong::text').extract_first(default='')     
        # #interest_sectl > div > div.rating_self.clearfix > div > div.rating_sum > span > a > span
        item['reviewCount']= response.css('div.rating_sum > span > a > span::text').extract()
        
        func = lambda x,key : x[key][0].strip() if x.has_key(key) else ''
        # #buyinfo-printed > ul > li > a   #购买连接 
        urlss = []
        urls = response.css('#buyinfo-printed > ul > li > a::attr(href)').extract()         
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
        item['otherSites']= urlss  

        return item 

if __name__ == "__main__":
    value = 'http://www.douban.com/tag/%E4%B8%89%E6%AF%9B/?focus=book'
    m = re.search("http://www\.douban\.com/tag/[^/]*/", value)
    if m:
        print m.group(1)


