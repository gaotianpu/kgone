# -*- coding: utf-8 -*-
import json

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html


class DoubanPipeline(object):
    def __init__(self,data_file):
        self.data_file = data_file
        self.file = open(data_file, 'wb') #lock?

    @classmethod
    def from_crawler(cls,crawler):
        return cls(data_file=crawler.settings.get('DATA_FILE'))  #cls ?

    def process_item(self, item, spider):
        line = json.dumps(dict(item))
        self.file.write(line+'\n')
        return item
    
    def open_spider(self, spider):
        pass

    def close_spider(self,spider):
        self.file.close()
