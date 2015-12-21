# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class DoubanItem(scrapy.Item): 
    Id = scrapy.Field()
    url = scrapy.Field()
    name = scrapy.Field()
    image = scrapy.Field() 
    isbn = scrapy.Field()
    subtitle = scrapy.Field()
    book_set = scrapy.Field()
    publisher = scrapy.Field()  #出版社？
    author = scrapy.Field()
    author1 = scrapy.Field()
    subtitle = scrapy.Field()
    translator = scrapy.Field() #yizhe?
    publish_date = scrapy.Field()
    price = scrapy.Field()
    pageCount = scrapy.Field()
    zhuangzhen = scrapy.Field() #装帧？
    bookInfo = scrapy.Field()
    authorInfo = scrapy.Field()
    otherSites = scrapy.Field()
    ebookId = scrapy.Field()
    tags = scrapy.Field()
    wantCount = scrapy.Field()
    readCount = scrapy.Field()
    readingCount = scrapy.Field()
    score = scrapy.Field()
    reviewCount = scrapy.Field()
 