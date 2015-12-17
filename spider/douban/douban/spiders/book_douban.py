#!/usr/bin/env python
# -*- coding: utf-8 -*-
import scrapy
from scrapy.selector import Selector
import urlparse
from lxml.html.clean import Cleaner
import re 
import sys
sys.path.append("../../")
from douban.items import DoubanItem

book_properties = {u'作者':'author',u'出版社':'puborg',u'原作名':'author1',u'译者':'translator',u'出版年':'publish_date',u'页数':'pageCount',u'定价':'price',u'装帧':'zhuangzhen',u'ISBN':'isbn'}

class BookDoubanSpider(scrapy.Spider):
    name = "book_douban"
    allowed_domains = ["book.douban.com"]
    start_urls = (
        'http://book.douban.com/subject/26586492/',
        # 'http://book.douban.com/',
    )

    def parse(self, response):
        yield self.parse_item(response) 
        # filename = 'tmp/' + response.url.split("/")[-2] + '.html'
        # with open(filename, 'wb') as f:
        #     f.write(response.body)

        # for href in response.css('a::attr(href)'):
        #     full_url = response.urljoin(href.extract())
        #     full_url = full_url.split('?')[0]
        #     yield scrapy.Request(full_url, callback=self.parse_item)

    def parse_item(self,response):
        item = DoubanItem()
        m = re.search(r'(\d+)',response.url)
        item['Id']=  m.group(0) if m else '' 
        item['url']= response.url
        item['name']= response.css('#wrapper > h1 > span::text').extract()[0] 
        item['image']= response.css('#mainpic > a > img::attr(src)').extract()[0]  

        intro = response.css('#info').extract()[0] #需要进一步的分拆？

        intro =  ''.join(''.join(intro.splitlines()).split('  ')) #？use reg?
        cleaner = Cleaner(allow_tags=['br'], remove_unknown_tags=False)
        for i in cleaner.clean_html(intro).replace("<div>",'').replace('</div>','').split('<br>'):             
            x = i.split(':') 
            print x[0],x[1] if len(x)>1 else ''
            if x[0].strip() in book_properties.keys():
                kk = book_properties[x[0].strip()]
                print kk
                item[kk] = x[1] if len(x)>1 else ''
            else:
                self.logger.info('#info is null %s', item['Id'])

        # #link-report > div:nth-child(1) > div
        item['bookInfo']= response.css('#link-report > div:nth-child(1) > div').extract()[0].strip() #需要进一步的分拆？
        # #content > div > div.article > div.related_info > div:nth-child(5) > div > div
        item['authorInfo']= response.css('div.related_info > div:nth-child(5) > div > div').extract()[0].strip() #需要进一步的分拆？        
        # #content > div > div.article > div.related_info > div:nth-child(1) > div > div.ebook-link > a
        ebookId = response.css('div.ebook-link > a::attr(href)').extract()[0].strip()  #电子书链接 
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
        item['score']= response.css('div.rating_self.clearfix > strong::text').extract()[0].strip() 
        # #interest_sectl > div > div.rating_self.clearfix > div > div.rating_sum > span > a > span
        item['reviewCount']= response.css('div.rating_sum > span > a > span::text').extract()[0].strip()  
        # #buyinfo-printed > ul > li > a
        urls = response.css('#buyinfo-printed > ul > li > a::attr(href)').extract() #购买连接 

        # for u in urls:
        #     q = urlparse.urlparse(u).query
        #     x = urlparse.parse_qs(q,True)
        #     print x, x['url'] if x.has_key('url') else ''

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


          
if __name__ == "__main__":
    u = urlparse.urlparse('http://www.douban.com/link2?type=bkbuy&subject=26586492&vendor=jingdong&price=2280&lowest=1900&pre=0&cntvendor=6&pos=2&srcsubj=26586492&srcpage=subject&url=http%3A%2F%2Fitem.jd.com%2F11776068.html&link2key=5ce0395542')
    print u


        