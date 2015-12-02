#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
os.system('mysqldump -h localhost -uroot -proot  -d kgb > kgb.sql')

#delete AUTO_INCREMENT=\d+ ? 
