/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 26 Jul 2017 10:16:35 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

struct A
{
	int a;
	A():a(0) {}
	A(int ta) : a(ta) {}
};

struct AA:public A
{
	int aa;
	AA():A(), aa(0) {}
	AA(int ta, int taa): A(ta), aa(taa) {}
};

int main()
{
	std::vector<A> vecA;
	AA s1 = AA(15, 111);
	AA s2 = AA(16, 121);

	vecA.push_back(s1);
	vecA.push_back(s2);
	for(std::vector<A>::iterator it = vecA.begin(); it != vecA.end(); ++it)
	{
		A* x = &(*it);
		AA* s = static_cast<AA*>(x);
		std::cout <<s->a << " " << s->aa << std::endl;
	}
	/*
	 * result
	 * 15 16
	 * 16 0
	 * */

	/*
	std::vector<A> vecA;
	vecA.push_back(AA(15,111));
	vecA.push_back(AA(16,121));
	for(std::vector<A>::iterator it = vecA.begin(); it != vecA.end(); ++it)
	{
		A* x = &(*it);
		AA* s = static_cast<AA*>(x);
		std::cout <<s->a << " " << s->aa << std::endl;
	}
	*/
	/*
	 * result
	 * 15 16
	 * 16 0
	 * */

	/*
	std::vector<A*> vecA;
	AA x1 = AA(15, 111);
	AA x2 = AA(16, 121);
	vecA.push_back(&x1);
	vecA.push_back(&x2);

	for(std::vector<A*>::iterator it = vecA.begin(); it != vecA.end(); ++it)
	{
		A* x = (*it);
		AA* s = static_cast<AA*>(x);
		std::cout <<s->a << " " << s->aa << std::endl;
	}
	*/
	/*
	 * result
	 * 15 111
	 * 16 121
	 * */

	return 0;
}
