# from bs4 import BeautifulSoup
# from urllib.request import Request, urlopen
# 
# # site= "http://www.mafengwo.cn/search/q.php?q=%E5%8C%97%E4%BA%AC&seid=D492A05D-80DF-4035-B4BB-4CFC6373F3CB"
# site= "http://www.mafengwo.cn/jd/10065/gonglve.html"
# hdr = {'User-Agent': 'Mozilla/5.0'}
# req = Request(site,headers=hdr)
# page = urlopen(req)
# soup = BeautifulSoup(page, "html.parser")
# print(soup)
# divs = soup.findAll("ul")
# # divs = soup.findAll("div")
# # print(soup)
# cnt = 0
# for div in divs:
#   cnt += 1
#   # print(cnt)
#   #print('type')
#   #print(type(div))
#   # print(div)
#   # if cnt == 5:
#   #   break
#   
#   class_val = div.get('class')
#   if class_val and class_val[0] == 'scenic-list':
#     print(div)
#     children = div.findChildren()
#     print('children_0')
#     print(children)
#     print('children_1')
#     print(class_val) 
#   # print(divs)
#   # print('---------------')
#   # print('---------------')
# print(cnt)

# coding=utf-8
from selenium import webdriver
import time

wd = webdriver.Chrome()
#wd.get("https://www.baidu.com")    # 打开百度浏览器
wd.get("http://www.mafengwo.cn/jd/10065/gonglve.html")    # 打开百度浏览器
time.sleep(5)
page_cnt = 0
while True:
  print(page_cnt)
  page_cnt += 1
  if page_cnt == 100:
    break
  #elements = (wd.find_elements_by_class_name('scenic-list'))
  elements = (wd.find_elements_by_class_name('scenic-list')[0].find_elements_by_tag_name('li'))
  print(elements)
  print(type(elements))
  for element in elements:
    #print(element)
    #print(type(element))
    print(element.find_elements_by_tag_name('h3')[0].text)
  # wd.find_element_by_id("kw").send_keys("selenium")   # 定位输入框并输入关键字
  time.sleep(3)   #等待3秒
  
  element = (wd.find_elements_by_class_name('pi'))[0]
  if not element:
    break
  print('button0')
  element.click()
  print('button1')
  time.sleep(5)   #等待3秒

#wd.find_element_by_id("su").click()   #点击[百度一下]搜索
time.sleep(3)   #等待3秒
wd.quit()   #关闭浏览器
