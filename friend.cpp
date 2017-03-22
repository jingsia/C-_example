/*************************************************************************
	> File Name: c.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 14 Mar 2017 09:30:42 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class B;

class A
{
	public:
		void SetA(int ss) { a = ss;}

	private:
		int a;

	friend B;
};

class B
{
	public:
		void SetB() { b = a.a;}
	private:
		int b;
		A a;
		/*
		 * 这里的a 可以直接调用A的私有成员等
		 * */
};

int main()
{
	B b;
	
	return 0;
}
