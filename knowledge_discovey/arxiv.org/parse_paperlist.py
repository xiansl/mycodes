#!/usr/bin/env python

import re
import sys
import os
import urllib2
from bs4 import BeautifulSoup

def main():
    html = urllib2.urlopen('https://arxiv.org/list/cs.AI/1801?show=1000').read()
    soup = BeautifulSoup(html, "html.parser")
    
    dt_list = soup.find_all('dt')
    dd_list = soup.find_all('dd')

    if len(dt_list) != len(dd_list):
        print 'Error dd != dt'
        return
    
    for i in range(0, len(dt_list)):
        try:
            print i
            paperid = dt_list[i].span.a.text.replace('arXiv:', '')
            print 'ID:', paperid
            title_tag = dd_list[i].div.find(attrs={"class": "list-title"})
            title_tag.span.extract()
            title_str = title_tag.text.replace('\n', '').strip()
            author_tag = dd_list[i].div.find(attrs={"class": "list-authors"})
            author_tag.span.extract()
            author_str = author_tag.text.replace('\n', '').strip()
            subject_tag = dd_list[i].div.find(attrs={"class": "list-subjects"})
            subject_tag.span.extract()
            subject_str = subject_tag.text.replace('\n', '').strip()
            print 'Title:', title_str
            print 'Authors:', author_str
            print 'Subjects:', subject_str
        except:
            continue

#    paper_list = soup.find_all(attrs={"class": "list-title"})
#    title_list = soup.find_all(attrs={"class": "list-title"})
#    for t in title_list:
#        s = BeautifulSoup(str(t), "html.parser")
#        s.span.extract()
#        tstr = s.contents[0].contents[1].replace('\n', '').strip()
#        print tstr

if __name__ == "__main__":
    main()


