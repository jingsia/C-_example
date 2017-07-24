/*************************************************************************
	> File Name: pthread_create.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Mon 24 Jul 2017 08:18:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<pthread.h>
#include<unistd.h>

pthread_t ntid;

void PrintPid(const char* s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	std::cout << "s==" << s << std::endl;
	std::cout << "pid==" << pid << " tid==" << tid << std::endl;
}

void *ThrFn(void* arg)
{
	PrintPid("new thread：");

	return ((void*)0);
}

int main(void)
{
	int err;
	err = pthread_create(&ntid, NULL, ThrFn, NULL);
	if(err != 0)
		std::cout << "err" << std::endl;

	PrintPid("main thread:");
	sleep(1);
}
