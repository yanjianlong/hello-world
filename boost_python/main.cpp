#include </usr/include/python2.7/Python.h>
#include <iostream>
using namespace std;
//g++ main.cpp -o main -lpython2.7
int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		cout << "Py_IsInitialized error" << endl;
		return -1;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('.')");
	PyRun_SimpleString("print sys.path");
	PyRun_SimpleString("import test_so");
	PyRun_SimpleString("test_so.Main()");
	return 0;	
}