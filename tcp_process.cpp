#include "tcp_process.h"

CTcpProcess::CTcpProcess(const string& name)
{
	cout << "CTcpProcess create" << endl;
	m_classname = name;
}

CTcpProcess::~CTcpProcess()
{
	cout << "CTcpProcess delete" << endl;
}

void CTcpProcess::LoginInfo(const string& function_name,
				const string& addinfo)
{
	cout << m_classname << function_name
		<< addinfo << endl;
}

void CTcpProcess::SuccessProcess()
{
	cout << "CTcpProcess::SuccessProcess" << endl;
}

void CTcpProcess::ErrorProcess()
{
	cout << "CTcpProcess::ErrorProcess" << endl;
}