/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 05 Jul 2017 07:40:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void GetA(int a, int b)
{
	std::cout << a << " " << b << std::endl;
}

template<typename A, int msg, typename B>
void Get(void (*p1)(A, B))
{
	int b = 10;
	p1(msg, b);
}

int main()
{
	Get<int, 15, int>(&GetA);

	return 0;
}
