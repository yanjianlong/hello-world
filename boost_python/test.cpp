#include "test.h"

void Test::PrintInfo()
{
	int size = GetFriendSize();
	for(int i = 0; i < size; i++)
		cout << m_friends_[i] << endl;
}


// int main()
// {
// 	CTest test;
// 	test.PrintInfo();
// }