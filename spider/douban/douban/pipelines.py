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
        # 放在初始化阶段，每次频繁的open/close ?
        self.client = pymongo.MongoClient(self.mongo_uri)
        self.db = self.client[self.mongo_db] 
        #创建索引？
        result = self.db[spider.name].create_index('Id',unique=True,background=True)
        result = self.db[spider.name].create_index('name',background=True)

    def close_spider(self,spider):
        self.client.close()


    def process_item(self, item, spider):   
        #去重，根据id判断是否已存在？  
        result = self.db[spider.name].replace_one({'Id':item['Id']},dict(item),True) 
        return item
    
    
if __name__ == '__main__': 
    with pymongo.MongoClient('mongodb://localhost:27017/') as client: 
        for x in client['douban']['douban_book'].find():
            pass
        print client['douban']['douban_book'].count()
        client.close()
