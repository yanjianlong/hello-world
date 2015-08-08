#coding:utf-8
"""
	Jan.Lonely Yan

"""
import recommend.simple_recommend
import bs4
import urllib2

URL_LIST = ["http://www.lampweb.org/linux/2/6.html",
			]

URL_LIST = ["http://www.jidi.com/", ]
RESULT_INDEX = {}

def GetUrl():
	if URL_LIST:
		return URL_LIST.pop(0)
	return None

def InitIndex(url):
	request = urllib2.Request(url)
	content = urllib2.urlopen(request).read()
	result_dict = bs4.BeautifulSoup(content, 'html.parser')
	return result_dict

def TestBeautifulSoup():
	while True:
		url = GetUrl()
		if not url or len(RESULT_INDEX) > 20:
			return
		print "get link:", url
		result_dict = InitIndex(url)
		links = result_dict('a')
		for cur_link in links:
			if "href" in dict(cur_link.attrs):
				cur_url = cur_link.attrs["href"]
				if cur_url[0:4] == "http" and cur_url not in RESULT_INDEX:
					URL_LIST.append(cur_url)
				# else:
				# 	print "error", cur_url
		RESULT_INDEX[url] = result_dict
		# print url, "finish"

def Main():
	# recommend.simple_recommend.TestRecommend()
	TestBeautifulSoup()
	print "*****************exist url:"
	for url in RESULT_INDEX:
		print url
if __name__ == "__main__":
	Main()