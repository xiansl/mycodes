#!/usr/bin/env python

from HTMLParser import HTMLParser
from htmlentitydefs import name2codepoint
import re
import sys
import os
import urllib2
from bs4 import BeautifulSoup

class Subject(object):
    def __init__(self, field=None, code=None, desc=None):
        self.field = field
        self.code = code
        self.desc = desc

class FieldParser(HTMLParser):
    lasttag = ''
    lastfield = ''
    lastcode = ''
    lastdesc = ''
    
    subjectlist = list()

    def handle_starttag(self, tag, attrs):
        if tag == 'h2':
            self.lasttag = 'h2'
        if tag == 'a':
            for attr in attrs:
                if attr[0] == 'href':
                    if attr[1].startswith('/list') and attr[1].endswith('recent'):
                        code = attr[1].split('/')[2]
                        if '.' in code:
                            self.lastcode = code
                            #print '-', code 
    def handle_data(self, data):
        if self.lasttag == 'h2':
            if not data.startswith("About"):
                self.lastfield = data
                #print self.lastfield
        if self.lastcode != '':
            if data != 'recent':
                self.lastdesc = data
                self.subjectlist.append(Subject(self.lastfield, self.lastcode, self.lastdesc))
                #print '--', data
    def handle_endtag(self, tag):
        if tag == 'h2':
            self.lasttag = ''
        if tag == 'a':
            self.lastcode = ''
    def print_subject(self):
        for s in self.subjectlist:
            print s.code + ':' + s.desc + '|' + s.field
    def returnlist(self):
        return self.subjectlist

class PaperListParser(HTMLParser):
    hastitle = False
    def handle_starttag(self, tag, attrs):
        if tag == 'div':
            for attr in attrs:
                if attr[0] == 'class' and 'list-title' in attr[1]:
                    self.hastitle = True
    def handle_data(self, data):
        if self.hastitle:
            print data
    def handle_endtag(self, tag):
        if self.hastitle:
            self.hastitle = False

def main():
    #parser = FieldParser()
    #f = open('arxiv-directory.html', 'r')
    #parser.feed(f.read())
    #parser.print_subject()
    #subjectlist = parser.returnlist()
    #for s in subjectlist:
    #    print s.code
    plparser = PaperListParser() 
    plpage = urllib2.urlopen('https://arxiv.org/list/cs.AI/1801?show=1000')
    plparser.feed(str(plpage.read()))


if __name__ == "__main__":
    main()


