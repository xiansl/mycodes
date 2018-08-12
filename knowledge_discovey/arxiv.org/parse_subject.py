#!/usr/bin/env python

import re
import sys
import os
import urllib2
from bs4 import BeautifulSoup

def main():
    html = urllib2.urlopen('https://arxiv.org/list/cs.AI/1801?show=1000').read()
    soup = BeautifulSoup(html)

if __name__ == "__main__":
    main()


