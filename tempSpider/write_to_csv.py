# coding=utf-8
import csv
with open('sites.csv', 'w', newline='', encoding='utf-8-sig') as file:
    writer = csv.writer(file)
    writer.writerow(["景点名称", "简介", "电话", "网址", "用时参考", "交通方式", "门票", "开放时间"])
    # writer.writerow(["北京", "北京","北京", "北京", "北京", "北京", "北京", "北京"])
