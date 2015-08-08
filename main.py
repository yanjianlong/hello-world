#coding:utf-8
"""
	Jan.Lonely Yan

"""
import recommend.simple_recommend
import bs4
import urllib2

def TestBeautifulSoup():
	url = "https://www.baidu.com/"
	request = urllib2.Request(url)
	content = urllib2.urlopen(request).read()
	print content

	result_dict = bs4.BeautifulSoup(content, 'html.parser')
	print result_dict.prettify()

	print result_dict("script")

def Main():
	# recommend.simple_recommend.TestRecommend()
	TestBeautifulSoup()

if __name__ == "__main__":
	Main()