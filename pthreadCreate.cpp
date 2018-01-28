/*************************************************************************
	> File Name: pthreadCreate.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Sun 28 Jan 2018 03:36:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define NUM_THREAD 8

//sleep 对于线程资源抢占的分析
//1的sleep 注释掉 2的sleep 不注释掉 运行的结果 先执行对应的子线程
//1的sleep 不注释掉 2的sleep 注释掉 运行的结果 先执行主线程
void *PrintHello(void* args)
{
	int thread_arg;
	//(1)
	//sleep(1);
	thread_arg = (int)(*((int*)args));
	printf("hello from thread %d\n", thread_arg);

	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf(" pid %lu tid %lu (0x%lx)\n", (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
	return NULL;
}

int main(void)
{
	int rc,t;
	pthread_t thread[NUM_THREAD];

	for(t = 0; t < NUM_THREAD; t++)
	{
		printf("creating thread %d \n", t);
		rc = pthread_create(&thread[t], NULL, PrintHello, &t);
		if(rc)
		{
			printf("ERROR: return code is %d\n", rc);
			return EXIT_FAILURE;
		}
		//(2)
		sleep(1);
	}
	sleep(5);
	for(t = 0; t < NUM_THREAD; t++)
		pthread_join(thread[t], NULL);
	return EXIT_SUCCESS;
}
	
