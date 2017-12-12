/*************************************************************************
	> File Name: pthread_key.c
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Mon 11 Dec 2017 11:18:47 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

static pthread_key_t str_key;

static pthread_once_t str_alloc_key_once = PTHREAD_ONCE_INIT;
static void str_alloc_key();
static void str_alloc_destroy_accu(void* accu);

char * str_accumulate(const char* s)
{
	char * accu;
	pthread_once(&str_alloc_key_once, str_alloc_key);
	accu=(char*)pthread_getspecific(str_key);
	if(accu==NULL)
	{
		accu=malloc(1024);
		if(accu==NULL) return NULL;
		accu[0]=0;

		pthread_setspecific(str_key, (void *)accu);
		printf("Thread %lx: allocating buffer at %p\n", pthread_self(), accu);
	}

	strcat(accu, s);
	return accu;
}

static void str_alloc_key()
{
	pthread_key_create(&str_key, str_alloc_destroy_accu);

	 printf("Thread %lx: allocated key %d\n",pthread_self(),str_key);
}

static void str_alloc_destroy_accu(void* accu)
{
	printf("Thread %lx: freeing buffer at %p\n",pthread_self(),accu);
	free(accu);
}

void * process(void * arg)
{
	char* res;
	res = str_accumulate("Resule of ");
	if(strcmp((char*)arg, "first") == 0)
		sleep(3);
	res = str_accumulate((char*)arg);
	res = str_accumulate(" thread");
	printf("Thread %lx: \"%s\"\n",pthread_self(),res);
	return NULL;
}

int main(int argc, char* argv[])
{
	char * res;
	pthread_t th1, th2;
	res = str_accumulate("Result of ");
	pthread_create(&th1, NULL, process, (void*)"first");
	pthread_create(&th2, NULL, process, (void*)"second");
	res = str_accumulate("initial thread");
	printf("Thread %lx: \"%s\"\n",pthread_self(),res);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	pthread_exit(0);
}
