#include "stdafx.h"
#include "test_process.h"
#include "tcp_process.h"
int main()
{
	CTcpProcess* myProcess = new CTcpProcess("tcp");
	CTestProcess* mytest = new CTestProcess("test_process");
	mytest->SetCommonProcess(myProcess);
	mytest->Process();
	delete mytest;
	return 0;
}