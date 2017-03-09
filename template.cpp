/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Thu 09 Mar 2017 02:29:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

template<typename T = int>
class A
{

	private:
		T a;
};

template<typename T = int, typename V = int>
class A1 : public A<T>
{
	private:
		V a1;
};

template<class T = A<int>, typename V = int>
class B
{
	public:
		void GetA()
		{
			std::cout << vecA.size() << std::endl;
		}

	private:
		std::vector< T > vecA;
};

int main()
{
	B<A<int>, int> b;
	b.GetA();

	return 0;
}
