/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 28 Feb 2017 11:31:29 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	std::vector<int*> a;
	int* b = new int(10);
	a.push_back(b);

	for(std::vector<int*>::iterator it = a.begin(); it != a.end();)
	{
		std::cout << *(*it) << std::endl;
		delete *it;
		(*it) = NULL;

		it = a.erase(it);
	}

	return 0;
}
