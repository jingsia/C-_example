/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 14 Mar 2017 02:23:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <vector>

int main()
{
	bool isStop = false;
	int i = 0;
	do
	{
		i +=1;
		if(i == 10)
			isStop = true;
		std::cout << i << std::endl;
	}
	while(!isStop);

	std::cout << "......................" << std::endl;

	std::vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);

	std::cout << "a.size = " << a.size() << std::endl;

	for(std::vector<int>::iterator it = a.begin(); it != a.end();)
	{
		std::cout << (*it) << std::endl;

		if((*it) == 20)
			a.erase(it);//erase 之后自动跳到下一个内容 所以++it
		else
			++it;

	}

	std::vector<int> list;

	std::cout << "list.size = " << list.size() << std::endl;

	list.swap(a);

	std::cout << "a.size = " << a.size() << std::endl;
	std::cout << "list.size = " << list.size() << std::endl;

	std::cout << "a.capacity = " << a.capacity() << std::endl;
	std::cout << "list.size = " << list.capacity() << std::endl;


	return 0;
}
