#Learing Scrapy 
## 什么是Scrapy?
先简单了解下scrapy是干什么的，为什么要用它?

## scrapy的基础体系

## 下载安装

## 第一个项目
项目目标：抓取豆瓣读书全部书籍信息

1. 启动命令行生成第一个项目
scrapy startproject douban   
项目目录
为啥会生成2级的douban目录？

2. 使用模板生成一个spider
scrapy genspider book_douban douban.com 
都干了哪些事情?
spiders/book_douban.py 
items.py pipelines.py setting.py 的改变项，以及它的意义

3. 运行spider
scrapy runspider ./spiders/book_douban.py

更多命令行工具，http://doc.scrapy.org/en/1.0/topics/commands.html

## spider
BookDoubanSpider

scrapy crawl dmoz
scrapy crawl dmoz -L ERROR
scrapy crawl dmoz -L ERROR -o book_douban.json

response对象
.css
.urljoin
.url
.body


### csspath
::text
::attr(href)
#wrapper h1 span   ===  #wrapper > h1 > <span></span>

css path 调试
1. 单个页面的调试
2. 随机挑选10个页面调试
3. 如何避免重复下载


delete
scrapy runspider ./spiders/book_douban.py -L ERROR
scrapy runspider ./spiders/book_douban.py -L ERROR -o book_douban.json


## 数据评估
覆盖度，人工从抓取源随机挑选100条记录，在已抓取库中查找是否已存在，可算出覆盖度

解析好的数据，存储在哪里？
对下载网页做本地缓存，在设定的时间内，已下载的网页无需再下载，节约网页获取成本？
如何设置下载的时间间隔、并发线程数?
每次简单调整xpath,csspath都要运行一次，开发效率略低?

<pre>
from lxml import html
from lxml.html.clean import clean_html
tree = html.parse('http://www.example.com')
tree = clean_html(tree)
text = tree.getroot().text_content()
</pre>

<pre>
from lxml.html.clean import Cleaner
html_text = "<html><head><title>Hello</title><body>Text</body></html>"
cleaner = Cleaner(allow_tags=[''], remove_unknown_tags=False)
cleaned_text = cleaner.clean_html(html_text)</pre>

<pre>
import re
TAG_RE = re.compile(r'<[^>]+>')
def remove_tags(text):
	return TAG_RE.sub('', text)
</pre>

<pre>
def remove_tags(text):
    return ''.join(xml.etree.ElementTree.fromstring(text).itertext())
</pre>

<pre>
<div id="info" class=""><span><span class="pl"> 作者</span>:<a class="" href="/search/%E6%9C%B1%E5%87%8C%E9%94%8B">朱凌锋</a></span><br><span class="pl">出版社:</span> 四川文艺出版社<br><span class="pl">出版年:</span> 2015-11<br><span class="pl">页数:</span> 240<br><span class="pl">定价:</span> 49.00<br><span class="pl">装帧:</span> 平装<br><span class="pl">ISBN:</span> 9787541141645<br></div>
</pre>

## deploy
1. 暂停&重启
2. 统计，多少次request,成功/失败比例，下载了多少次
3. 查看代码，该怎么增加日志

Crawled 45 pages (at 45 pages/min), scraped 45 items (at 45 items/min)

