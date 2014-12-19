#ifndef __TEMPLATE_PROCESS__
#define __TEMPLATE_PROCESS__
#include "function_template.h"


class CProcess
{
private:
	ICommonProcess* m_process;
public:
	CProcess();
	virtual ~CProcess();
	virtual void Process() = 0;

	void SetCommonProcess(ICommonProcess* process);

	void CommonLog(const string& function_name, 
				const string& addinfo);
	void SuccessProcess(const string& function_name, 
				const string& addinfo);
	void ErrorPrrocess(const string& function_name, 
				const string& addinfo);
};


#endif