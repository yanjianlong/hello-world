#include "test.h"

CTest::CTest(const string& name)
{
	cout << "CTest create" << endl;
	m_classname = name;
}

CTest::~CTest()
{
	cout << "CTest delete" << endl;
}

void CTest::LoginInfo(const string& function_name,
				const string& addinfo)
{
	cout << m_classname << function_name
		<< addinfo << endl;
}

void CTest::SuccessProcess()
{
	cout << "CTest::SuccessProcess" << endl;
}

void CTest::ErrorProcess()
{
	cout << "CTest::ErrorProcess" << endl;
}