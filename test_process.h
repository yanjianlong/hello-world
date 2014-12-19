#ifndef __TEST_PROCESS__
#define __TEST_PROCESS__

#include "template_process.h"
class CTestProcess
	: public CProcess
{
private:
	string m_process_name_;
public:
	CTestProcess(const string& process_name);
	~CTestProcess();
	void Process();
	void CommonLog(const string& function_name, 
				const string& addinfo);
};


#endif