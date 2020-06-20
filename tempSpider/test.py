# !/usr/local/bin/python3

# from bs4 import BeautifulSoup
# from urllib.request import urlopen
# html = urlopen("https://www.csdn.net/").read().decode('utf-8')
# soup = BeautifulSoup(html,"html.parser")
# titles=soup.select("h3[class='company_name'] a")
# for title in titles:
#     print(title.get_text(),title.get('href'))

from bs4 import BeautifulSoup
from urllib.request import Request, urlopen

# site= "http://www.mafengwo.cn/search/q.php?q=%E5%8C%97%E4%BA%AC&seid=D492A05D-80DF-4035-B4BB-4CFC6373F3CB"
site= "http://www.mafengwo.cn/jd/10065/gonglve.html"
hdr = {'User-Agent': 'Mozilla/5.0'}
req = Request(site,headers=hdr)
page = urlopen(req)
soup = BeautifulSoup(page, "html.parser")
print(soup)
divs = soup.findAll("ul")
# divs = soup.findAll("div")
# print(soup)
cnt = 0
for div in divs:
  cnt += 1
  # print(cnt)
  #print('type')
  #print(type(div))
  # print(div)
  # if cnt == 5:
  #   break
  
  class_val = div.get('class')
  if class_val and class_val[0] == 'scenic-list':
    print(div)
    children = div.findChildren()
    print('children_0')
    print(children)
    print('children_1')
    print(class_val) 
  # print(divs)
  # print('---------------')
  # print('---------------')
print(cnt)

# response = urllib.request.urlopen(
#  'https://shenyang.craigslist.org/')
# print(response.read())
# html = urlopen("http://www.mafengwo.cn/jd/10065/gonglve.html")
# html.read().decode('utf-8')
# soup = BeautifulSoup(html,"html.parer")
# titles=soup.select("ul[class='scenic-list clearfix']") 
# for title in titles:
#     print(title)

# import urllib.request
# response = urllib.request.urlopen(
#         'https://shenyang.craigslist.org/')
# print(response.read())

# from bs4 import BeautifulSoup
# 
# with open("index.html", "r") as f:
#     
#     contents = f.read()
# 
#     soup = BeautifulSoup(contents, 'lxml')
# 
#     print(soup.h2)
#     print(soup.head)
#     print(soup.li)
