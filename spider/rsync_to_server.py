# -*- coding: utf-8 -*-
import os

os.system('rsync -av douban  --exclude-from=excludefiles.txt gaotianpu@192.168.1.111:/home/gaotianpu/spiders/')
