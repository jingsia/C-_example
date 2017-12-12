/*************************************************************************
	> File Name: thread_mutex.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 12 Dec 2017 10:05:58 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<pthread.h>
#define NUM_THREAD 5
int sum = 0;
pthread_mutex_t sum_mutex;

void* say_hello(void* args)
{
	cout << "hello in thread " << *((int*)args) << endl;
	pthread_mutex_lock(&sum_mutex);
	cout << "before sum is " << sum << "in thread " <<  *(reinterpret_cast<int*>(args)) <<endl;
	sum += *((int*)args);
	cout << "after sum is " << sum << "in thread" << *((int*)args) << endl;
	pthread_mutex_unlock(&sum_mutex);
	pthread_exit(0);
}

int main()
{
	pthread_t tids[NUM_THREAD];
	int indexs[NUM_THREAD];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&sum_mutex, NULL);
	for(int i = 0 ; i < NUM_THREAD; ++i)
	{
		indexs[i] = i;
		int ret = pthread_create(&tids[i], &attr, say_hello, ( void* )&( indexs[i] ));
		if(ret != 0)
		{
			cout << "create error " << ret <<endl;
		}
	}
	pthread_attr_destroy(&attr);
	void* status;
	for(int i = 0; i < NUM_THREAD; ++i)
	{
		int ret = pthread_join(tids[i], &status);
		if(ret != 0)
		{
			cout << "pthread error " << ret << endl;
		}
	}

	cout << "finally sum is "  << sum << endl;
	pthread_mutex_destroy(&sum_mutex);
	return 0;
}
