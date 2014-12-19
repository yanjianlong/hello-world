#include "template_process.h"
CProcess::CProcess()
	: m_process(NULL)
{
	cout << "CProcess create" << endl;
}

CProcess::~CProcess()
{
	cout << "CProcess delete" << endl;
}

void CProcess::SetCommonProcess(ICommonProcess* process)
{
	m_process = process;
}

void CProcess::CommonLog(const string& function_name, 
				const string& addinfo)
{
	if (NULL == m_process)
	{
		cout << "CProcess::CommonLog m_process empty" << endl;
		return;
	}
	m_process->LoginInfo(function_name, function_name);
}

void CProcess::SuccessProcess(const string& function_name, 
				const string& addinfo)
{
	CommonLog(function_name, function_name);
	if (NULL == m_process)
	{
		cout << "CProcess::SuccessProcess m_process empty" << endl;
		return;
	}
	m_process->SuccessProcess();
}
void CProcess::ErrorPrrocess(const string& function_name, 
				const string& addinfo)
{
	CommonLog(function_name, function_name);
	if (NULL == m_process)
	{
		cout << "CProcess::ErrorPrrocess m_process empty" << endl;
		return;
	}
	m_process->ErrorProcess();
}