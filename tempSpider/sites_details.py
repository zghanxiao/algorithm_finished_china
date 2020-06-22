# coding=utf-8
from selenium import webdriver
import time
import csv

def write_row(outputs): 
  print('before_writing_row')
  with open('sites.csv', 'a+', newline='', encoding='utf-8-sig') as file:
    writer = csv.writer(file)
    # writer.writerow(["景点名称", "简介", "电话", "网址", "用时参考", "交通方式", "门票", "开放时间"])
    writer.writerow(outputs)
  print('after_writing_row')
  pass

def trim_data(str):
  element_str = str
  element_str = element_str.strip()
  element_list = element_str.split('\n')
  delimiter = ''
  element_str = delimiter.join(element_list)
  return element_str

def read_urls():
  file = open('beijing_sites_url.out', 'r')
  urls = []
  
  try:
    text_lines = file.readlines()
    for line in text_lines:
      urls.append(line)  
  finally:
      file.close()
  return urls    

outputs = []
wd = webdriver.Chrome()
#wd.get("https://www.baidu.com")    # 打开百度浏览器


urls = read_urls()


for url in urls:
  wd.get(url)
  #wd.get("http://www.mafengwo.cn/jd/10065/gonglve.html")    # 打开百度浏览器
  time.sleep(5)
  # print(page_cnt)
  #elements = (wd.find_elements_by_class_name('scenic-list'))
  title = wd.find_elements_by_class_name('title')[0].find_element_by_tag_name('h1')
  print(title.text)
  outputs.append(title.text)
  details = wd.find_element_by_css_selector('.mod.mod-detail')
  element = details.find_elements_by_class_name('summary')[0]
  outputs.append(trim_data(element.text))
  
  element = details.find_elements_by_class_name('tel')[0].find_elements_by_class_name("content")[0]
  print(element.text)
  outputs.append(element.text)
  
  element = details.find_elements_by_class_name('item-site')[0].find_elements_by_class_name('content')[0]
  print(element.text)
  outputs.append(element.text)
  
  element = details.find_elements_by_class_name('item-time')[0].find_elements_by_class_name('content')[0]
  print(element.text)
  outputs.append(element.text)
  
  dl_elements = details.find_elements_by_tag_name('dl')
  for dl_element in dl_elements:
    # print(dl_element)
    # print(type(dl_element))
    print('-----------------')
    print(dl_element.text)
    outputs.append(trim_data(dl_element.text))
  write_row(outputs)
  time.sleep(15)   #等待3秒
