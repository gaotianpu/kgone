#!/usr/bin/env python
# -*- coding: utf-8 -*-
import re
import random
import base64
import logging


# https://github.com/aivarsk/scrapy-proxies

class RandomHttpProxy(object):
    def __init__(self, settings,stats):
        self.proxy_list = settings.get('PROXY_LIST')
        self.stats = stats 

        self.proxies = {}
        with open(self.proxy_list) as fin:
            for line in fin.readlines():
                parts = re.match('(\w+:\w+@)?(.+)', line) #稍微改造下，我的代理文件不太一样
                # Cut trailing @
                if parts.group(1):
                    user_pass = parts.group(1)[:-1]
                else:
                    user_pass = ''
                self.proxies[parts.group(2).strip()] = user_pass.strip()
                fin.close()

        # source code 
        # fin = open(self.proxy_list)
        # self.proxies = {}
        # for line in fin.readlines():
        #     parts = re.match('(\w+://)(\w+:\w+@)?(.+)', line)
        #     # Cut trailing @
        #     if parts.group(2):
        #         user_pass = parts.group(2)[:-1]
        #     else:
        #         user_pass = ''
        #     self.proxies[parts.group(1) + parts.group(3)] = user_pass
        # fin.close()

    @classmethod
    def from_crawler(cls, crawler):
        return cls(crawler.settings,crawler.stats)

    def process_request(self, request, spider):
        # Don't overwrite with a random one (server-side state for IP)
        if 'proxy' in request.meta:
            return

        proxy_address = random.choice(self.proxies.keys())
        proxy_user_pass = self.proxies[proxy_address]

        request.meta['proxy'] = 'http://' + proxy_address
        if proxy_user_pass:
            basic_auth = 'Basic ' + base64.encodestring(proxy_user_pass)
            request.headers['Proxy-Authorization'] = basic_auth

    def process_exception(self, request, exception, spider):
        proxy = request.meta['proxy'].replace('http://','')
        logging.warning('Removing failed proxy <%s>, %d proxies left' % (proxy, len(self.proxies)))
        self.stats.set_value('proxy_len',len(self.proxies))
        try:
            del self.proxies[proxy] 
        except ValueError:
            pass

if __name__ == "__main__":
    lines = ['username:password@host2:port','host1:port']
    for line in lines : 
        parts = re.match('(\w+:\w+@)?(.+)', line)
        print parts.group(0)
        print parts.group(1)
        print parts.group(2)
        # print parts.group(3)
        print ''



