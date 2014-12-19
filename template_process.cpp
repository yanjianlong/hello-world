#include "template_process.h"
CProcess::CProcess()
	: m_process_(NULL)
{
	cout << "CProcess create" << endl;
}

CProcess::~CProcess()
{
	cout << "CProcess delete" << endl;
	if(NULL != m_process_)
	{
		delete m_process_;
	}
	m_process_ = NULL;
}

void CProcess::SetCommonProcess(ICommonProcess* process)
{
	m_process_ = process;
}
void CProcess::SuccessProcess(const string& function_name, 
				const string& addinfo)
{
	CommonLog(function_name, function_name);
	if (NULL == m_process_)
	{
		cout << "CProcess::SuccessProcess m_process_ empty" << endl;
		return;
	}
	m_process_->SuccessProcess();
}
void CProcess::ErrorPrrocess(const string& function_name, 
				const string& addinfo)
{
	CommonLog(function_name, function_name);
	if (NULL == m_process_)
	{
		cout << "CProcess::ErrorPrrocess m_process_ empty" << endl;
		return;
	}
	m_process_->ErrorProcess();
}