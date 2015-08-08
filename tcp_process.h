#ifndef __TCP_PROCESS_H__
#define __TCP_PROCESS_H__
#include "function_template.h"
class CTcpProcess
	: public ICommonProcess
{
private:
	string m_classname;
public:
	CTcpProcess(const string& name);
	~CTcpProcess();
	void SuccessProcess();
	void ErrorProcess();
	void LoginInfo(const string& function_name,
				const string& addinfo);
};

#endif