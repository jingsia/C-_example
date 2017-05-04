/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 26 Apr 2017 10:00:02 PM CST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>

int main(void)
{
	printf("hello world from process ID %ld\n", getpid());

	return 0;
}
