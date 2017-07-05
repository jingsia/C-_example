/*************************************************************************
	> File Name: pthread_join.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 21 Jun 2017 01:30:13 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
using namespace std;

#define NUM_THREADS 5
void *wait(void *t)
{
	int i;
	long tid;
	tid = (long)t;
	sleep(1);
	cout << "sleeping in thread" << endl;
	cout << "thread with id :" << tid << "....exiting" << endl;
	pthread_exit(NULL);
}

int main()
{
	int rc;
	int i;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	//初始化并设置线程为可连接的
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for(i = 0; i < NUM_THREADS; ++i)
	{
		cout << "main() : createing thread " << i << endl;
		rc = pthread_create(&threads[i], NULL, wait, (void*)i);
		if(rc)
		{
			cout << "error:unable to create thread" << rc << endl;
			exit(-1);
		}
	}

	//删除属性 并等待其它线程
	pthread_attr_destroy(&attr);
	for(i = 0; i < NUM_THREADS; ++i)
	{
		rc = pthread_join(threads[i], &status);
		if(rc)
		{
			cout << "ERROR unbale to join " << rc << endl;
			exit(-1);
		}
		cout << "main completed thread id ; " << i;
		cout << " exiting with status : " << status << endl;
	}

	cout << "main:program exiting." << endl;
	pthread_exit(NULL);

	return 0;
}


