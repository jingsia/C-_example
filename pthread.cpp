/*************************************************************************
	> File Name: pthread.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 21 Jun 2017 11:19:23 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<pthread.h>

#define NUM_THREADS 5

struct ThreadData
{
	int id;
	char* message;
	ThreadData(int i, char* m):id(i), message(m) {}
	ThreadData() : id(0),message("") {}
};

void* say_hello(void* args)
{
	ThreadData tid = *((struct ThreadData*)args);
	cout << "hello runoob!" << "id ==>" << tid.id  << "message-->" << tid.message <<  endl;
}

int main()
{
	pthread_t tids[NUM_THREADS];
	ThreadData index[NUM_THREADS];

	for(int i = 0; i < NUM_THREADS; ++i)
	{
		cout << "main() ==> create thread " << i << endl;
		index[i] = ThreadData(i, "this is message");
		int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&(index[i]));
		if(ret != 0)
		{
			cout << "pthread_create:error_code=" << ret << endl;
		}
	}

	pthread_exit(NULL);
}
