#include "test_process.h"

CTestProcess::CTestProcess(const string& process_name)
	: m_process_name_(process_name)
{
	cout << "CTestProcess::CTestProcess" << endl;
}


CTestProcess::~CTestProcess()
{
	cout << "CTestProcess::~CTestProcess" << endl;
}


void CTestProcess::Process()
{
	cout << "CTestProcess::Process" << endl;
	SuccessProcess("SuccessProcess", "success");
	ErrorPrrocess("ErrorPrrocess", "error");
}

void CTestProcess::CommonLog(const string& function_name, 
				const string& addinfo)
{
	cout << "CTestProcess " << function_name << " "
		<< addinfo << " name " << m_process_name_ << endl;
}


