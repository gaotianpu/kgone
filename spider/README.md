## Scrapy 

### 1.  实现网络爬虫，需要解决哪些问题？
http://www.cnblogs.com/onlytiancai/archive/2008/04/19/1161425.html

### 2. Scrapy的架构
Scrapy的应用场景，垂直、定向爬取网页并从网页中提取结构化数据

http://doc.scrapy.org/en/1.0/topics/architecture.html

### 3. 下载安装
http://doc.scrapy.org/en/1.0/intro/install.html

### 4. Scrapy入门
http://doc.scrapy.org/en/1.0/intro/tutorial.html

### 5. 从网页中提取结构化数据
http://doc.scrapy.org/en/1.0/topics/selectors.html

python shell url #开发调试阶段 

### 6. 保存提取的结构化数据
http://doc.scrapy.org/en/1.0/topics/item-pipeline.html

### 7. crawlspider
http://doc.scrapy.org/en/1.0/topics/spiders.html#crawlspider

### 8. 使用http代理
https://github.com/aivarsk/scrapy-proxies/blob/master/randomproxy.py
http://doc.scrapy.org/en/1.0/topics/downloader-middleware.html#module-scrapy.downloadermiddlewares.httpproxy

#### 9. 参数设置
DOWNLOAD_DELAY = 1
AUTOTHROTTLE_ENABLED = True
COOKIES_ENABLED = False
RETRY_TIMES = 10
RETRY_HTTP_CODES = [500, 503, 504, 400, 403, 404, 408]

### 10. 常见问题
