#ifndef __CTEST_H__
#define __CTEST_H__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Test
{
public:
	int m_age_;
	vector<string> m_friends_;

public:
	Test()
		: m_age_(24)
	{
		for(int i = 0; i < m_age_; i++)
			m_friends_.push_back("test");
		cout << "CTest::CTest()" << endl;
	}
	~Test()
	{
		cout << "CTest::~CTest()" << endl;
	}
	int GetAge()
	{
		return m_age_;
	}
	int GetFriendSize()
	{
		return m_friends_.size();
	}
	void PrintInfo();
};


#endif