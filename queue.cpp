/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 20 Jun 2017 06:21:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include <cstdlib>
#include <queue>

int main()
{
	int e,n,m;
	queue<int> q1;

	for(int i = 0; i < 10; ++i)
		q1.push(i*10 + i);

	if(!q1.empty())
		cout << "duilie bu kong \n";

	n = q1.size();

	cout << "q1 size==" << n << endl;

	m = q1.back();
	cout << "q1 back==" << m << endl;

	for(int j = 0; j < n; ++j)
	{
		e = q1.front();
		cout << " front ==" << e << endl;
		q1.pop();
	}

	if(q1.empty())
		cout << "duilie kong\n";

	system("PAUSE");

	return 0;
}
