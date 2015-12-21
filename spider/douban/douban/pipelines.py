# -*- coding: utf-8 -*-
import pymongo

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html


class DoubanPipeline(object):  
    def __init__(self, mongo_uri, mongo_db):
        self.mongo_uri = mongo_uri
        self.mongo_db = mongo_db

    @classmethod
    def from_crawler(cls,crawler):
        return cls(
            mongo_uri = crawler.settings.get('MONGO_URI'),
            mongo_db = crawler.settings.get('BOT_NAME')  #crawler.settings.get('MONGO_DATABASE')
        )

    def open_spider(self, spider):
        self.client = pymongo.MongoClient(self.mongo_uri)
        self.db = self.client[self.mongo_db]

    def close_spider(self,spider):
        self.client.close()


    def process_item(self, item, spider):            
        self.db[spider.name].insert(dict(item))
        return item
    
    
if __name__ == '__main__':
    ##books.douban_book
    with pymongo.MongoClient('mongodb://localhost:27017/') as client:
        db = client['books']
        # db['douban_books'].insert({'a':'b'})
        for x in db['douban_book'].find():
            print x
        client.close()
