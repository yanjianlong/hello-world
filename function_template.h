#ifndef __FUNCTION_TEMPLATE__
#define __FUNCTION_TEMPLATE__
#include "stdafx.h"

class ICommonProcess
{
public:
	virtual void SuccessProcess() = 0;
	virtual void ErrorProcess() = 0;
	virtual void LoginInfo(const string& function_name,
				const string& addinfo) = 0;
};

// typedef void (ICommonProcess::*LOG_FUNCTION)(const string& function_name, 
// 					const string& addinfo);

// typedef void (ICommonProcess::*SUCCESS_FUNCTION)();

// typedef void (ICommonProcess::*ERROR_FUNCTION)();

#endif