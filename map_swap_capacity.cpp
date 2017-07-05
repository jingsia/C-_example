/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 14 Mar 2017 02:23:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <map>

int main()
{
	std::map<int, int> a;
	a.insert(std::make_pair(15,14));
	a.insert(std::make_pair(11,18));
	a.insert(std::make_pair(12,16));
	a.insert(std::make_pair(16,10));

	for(std::map<int, int>::iterator it = a.begin(); it != a.end();)
	{
		if(it->second == 18)
		{
			std::cout << "is 18  " << it->second << std::endl;
			a.erase(it++); //这里和vector不一样 都需要++
		}
		else
		{
			std::cout << "not 18  " << it->second << std::endl;
			++it;
		}

	}

	return 0;
}
