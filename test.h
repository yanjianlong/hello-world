#ifndef __TEST_H__
#define __TEST_H__
#include "function_template.h"
class CTest
	: public ICommonProcess
{
private:
	string m_classname;
public:
	CTest(const string& name);
	~CTest();
	void SuccessProcess();
	void ErrorProcess();
	void LoginInfo(const string& function_name,
				const string& addinfo);
};

#endif