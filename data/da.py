#!/usr/bin/env python
# -*- coding: utf-8 -*-
import web
from config import host,db,user,pw
import util
# import os
import sys  
reload(sys)  
sys.setdefaultencoding('utf-8')  


db = web.database(dbn='mysql', host=host, db=db, user=user, pw=pw)

#first import entities and entity_page
#1+, merge entity and entity_page
#update,
def load_entities_pkids(pk_ids):
    return db.select('entities',what="pk_id,type_id,name",where="pk_id in $pk_ids",vars=locals())

def load_entities(type_id):
    return db.select('entities',what="pk_id,type_id,name",where="type_id=$type_id",vars=locals())

def save_char_entity(entity):
    chars = util.str2char(entity.name)
    db.query('update char_entities set status=0 where entity_id=%d' % (entity.pk_id))
    li = []
    for c in chars:
        li.append("('%s',%d,%d,%d,1)"%( c['char'],c['count'],entity.type_id,entity.pk_id ) )
    # print ','.join(li)
    db.query('replace into char_entities (char_one,char_count,entity_type_id,entity_id,status)values%s'%(','.join(li)))

def search(name):
    chars = util.str2char(name)
    condi = ' or '.join(["char_one='%s'"%(c['char']) for c in chars])
    result = db.query("""select  entity_id,count(entity_id) as entity_count ,sum(char_count) as char_count_sum from char_entities  
        where %s  group by entity_id order by sum(char_count) desc; """ % (condi)) #char_one='星' or char_one='美' 
    return list(result)[0:3]

def load_tmp_pages():
    return db.select('entity_pages_tmp',what="pk_id,name",where="entity_id is null ",vars=locals())


def set_entity_id():
    rows = load_tmp_pages()
    for r in rows:
        entities = search(r.name)
        pk_id = r.pk_id
        db.update('entity_pages_tmp',entity_id=entities[0].entity_id,where="pk_id=$pk_id",vars=locals())
        # print entities[0].entity_id,entities[0].char_count_sum,r.name

def run(type_id):
    entities = load_entities(type_id)
    for entity in entities:
        save_char_entity(entity)
         
def import_entitiy_page_tmp(entity_type_id,lines):
    #lines[0] = 
    rows = []
    for l in lines:
        segments = l.url.split('/')
        domain = segments[2]
        domain_main ='.'.join(segments[2].split('.')[-2:])
        rows.append({'entity_type_id':entity_type_id,
            'raw_entity_id':l.raw_entity_id,
            'name':l.name,
            'url':l.url,
            'domain_main':domain_main,
            'domain':domain,
            'create_date':'now()',
            'status':'1'
            })         
    _import_entitiy_page_tmp(rows) 
 
def _import_entitiy_page_tmp(rows):
    db.supports_multiple_insert = True     
    db.multiple_insert('entity_pages_tmp', values=rows)

import csv
def import_theaters(lfile):     
    with open(lfile,'rb') as f:
        reader = csv.reader(f, delimiter=',')
        rows = []
        for ent_type,city,raw_id,url,name in reader: 
            rows.append(web.storage(entity_type=ent_type,raw_entity_id=raw_id,name=name,url=url))            
        import_entitiy_page_tmp(4,rows)

if __name__ == "__main__":
    # import_theaters('/Users/gaotianpu/Downloads/movies/dianping/mtheater.csv')
    # import_theaters('/Users/gaotianpu/Downloads/movies/nuomi/mtheater.csv')
    set_entity_id()
    
    # s ='http://bj.nuomi.com/cinema/beabdbf48fb9b3817169d3a1'
    # segments = s.split('/')
    # print segments[2],segments[2].split('.')[-2]
    # 
    

    # r = load_entities_pkids([1,2,3])
    # for i in r:
    #     print i
    # run(4)
    # txt = u'星美国际影城(北京世界城店)'
    # print util.str2char(txt)

    # txt = re.sub("[\s+\.\!\/_,$%^*(+\"\']+|[+——！，。？、~@#￥%……&*()（）]+".decode("utf8"), "".decode("utf8"),txt) 
    # li = []
    # for char in list(set(txt)):
    #     li.append({'char':char,'count':txt.count(char)})
    # print li  

    # print list(s)
    # print set(s)
    # for i in range(0,len(s)):
    #     print s[i]
    # l =  load_entities(4)
    # for item in l:
    #     print item