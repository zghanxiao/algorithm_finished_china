# coding=utf-8
from selenium import webdriver
import time

wd = webdriver.Chrome()
#wd.get("https://www.baidu.com")    # 打开百度浏览器
wd.get("http://www.mafengwo.cn/poi/3474.html")
#wd.get("http://www.mafengwo.cn/jd/10065/gonglve.html")    # 打开百度浏览器
time.sleep(5)
page_cnt = 0
while True:
  # print(page_cnt)
  page_cnt += 1
  if page_cnt == 100:
    break
  #elements = (wd.find_elements_by_class_name('scenic-list'))
  elements = (wd.find_elements_by_class_name('scenic-list')[0].find_elements_by_tag_name('li'))
  # print(elements)
  # print(type(elements))
  for element in elements:
    # print(element)
    # print(type(element))
    # print(element.find_elements_by_tag_name('h3')[0].text)
    print(element.find_elements_by_tag_name('a')[0].get_attribute('href'))
  # wd.find_element_by_id("kw").send_keys("selenium")   # 定位输入框并输入关键字
  time.sleep(5)   #等待3秒
  
  # element = (wd.find_elements_by_class_name('pi pg-next'))[0]
  try:
    element = wd.find_element_by_css_selector('.pi.pg-next')
  except:
    break
  # print('button0')
  element.click()
  # print('button1')
  time.sleep(5)   #等待3秒

#wd.find_element_by_id("su").click()   #点击[百度一下]搜索
time.sleep(3)   #等待3秒
wd.quit()   #关闭浏览器
