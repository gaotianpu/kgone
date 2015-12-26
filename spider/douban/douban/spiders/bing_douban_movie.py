# -*- coding: utf-8 -*-
import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule


class BingDoubanMovieSpider(CrawlSpider):
    name = "bing_douban_movie"
    allowed_domains = ["cn.bing.com",'douban.com']
    start_urls = (
        'http://cn.bing.com/search?q=site%3amovie.douban.com%2fsubject%2f&first=1',
    )

    #bing的url规则有些乱，fingerprint去重可能就比较差 
    # 1.按照规则生成start_urls? 2.写好正则过滤？
    # bing可抓取的结果并不全，放弃这种方案
    rules = [
        Rule(LinkExtractor(allow=r'^http://cn\.bing\.com/search*'),callback='parse_page',follow=True),
        Rule(LinkExtractor(allow=r'^http://movie\.douban\.com/subject/(\d+)/$'),callback='parse_item',follow=False),
    ]

    def parse_page(self,response):
        print response.url

    def parse_item(self, response):
        # response.css('#content > h1 > span:nth-child(1)::text').extract_first()
        # response.css('#info > span:nth-child(1) > span.attrs > a').extract()
        # #info > span:nth-child(3) > span.attrs > a
        print response.url
