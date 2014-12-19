#ifndef __TEMPLATE_PROCESS__
#define __TEMPLATE_PROCESS__
#include "function_template.h"


class CProcess
{
private:
	ICommonProcess* m_process_;
public:
	CProcess();
	virtual ~CProcess();
	virtual void Process() = 0;
	virtual void CommonLog(const string& function_name, 
				const string& addinfo) = 0;
	void SetCommonProcess(ICommonProcess* process);
	
	void SuccessProcess(const string& function_name, 
				const string& addinfo);
	void ErrorPrrocess(const string& function_name, 
				const string& addinfo);
};


#endif