#include "stdafx.h"
#include "test_process.h"
#include "tcp_process.h"
void TestProcess()
{
	CTcpProcess* myProcess = new CTcpProcess("tcp");
	CTestProcess* mytest = new CTestProcess("test_process");
	mytest->SetCommonProcess(myProcess);
	mytest->Process();
	delete mytest;
}

void TestStruct()
{
	struct sdshdr{
		int len;
		int free;
		char buf[];
	};	
	cout << "sizeof:" << sizeof(sdshdr) << endl;
}

int main()
{
	TestStruct();
	return 0;
}