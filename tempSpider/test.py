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
