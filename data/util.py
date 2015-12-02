#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import re
import sys
reload(sys)
sys.setdefaultencoding( "utf-8" )


def completeInnerUrl(current_url,inner_url):
    if inner_url.startswith('/'):
        return  'http://%s%s' % (current_url.split('/')[2],inner_url)
    elif inner_url.startswith('http://'):
        return inner_url
    else : 
        return  'http://%s/%s' % ('/'.join(current_url.split('/')[2:-1]),inner_url)

def load_proxies():
    with open('proxies.txt','r') as f:
        proxies = f.readlines()
        return proxies if proxies else []

def save_file(lfile,li): 
    with open(lfile,'w') as f:
        f.write('\r\n'.join(li)+'\r\n')
        f.close()


def str2char(txt):
    txt = re.sub("[\s+\.\!\/_,$%^*(+\"\']+|[+——！，。？、~@#￥%……&*()（）]+".decode("utf8"), "".decode("utf8"),txt) 
    li = []
    for char in list(set(txt)):
        li.append({'char':char,'count':txt.count(char)})
    return li 