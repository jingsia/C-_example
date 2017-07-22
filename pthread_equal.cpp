/*************************************************************************
	> File Name: pthread_equal.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Sat 22 Jul 2017 03:15:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<pthread.h>

int main()
{
	pthread_t pid1;
	pthread_t pid2;

	pid1 = pthread_self();
	pid2 = pthread_self();

	std::cout << pid1 << " " << pid2 << "'" << pthread_equal(pid1, pid2);

	return 0;
}
