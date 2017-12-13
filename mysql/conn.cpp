/*************************************************************************
	> File Name: conn.c
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 13 Dec 2017 01:36:22 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<mysql/mysql.h>
#include <sys/time.h>
#include<string.h>
//#include<stdlib.h>
using namespace std;

template <typename Type>
std::string Itoa(Type n, int dec = 10)
{
	char buffer[256] = {0};
	char* p = buffer;

	do
	{
		*p++ = "0123456789"[n % dec];
		n /= dec;
		if (static_cast<size_t>(p - buffer) > sizeof(buffer)) return "";
	} while (n);

	buffer[p - buffer] = 0;

	int i, j;
	for (i = 0, j = (int)strlen(buffer) - 1; i < j; i++, j--)
	{
		buffer[j] = buffer[i] + buffer[j];
		buffer[i] = buffer[j] - buffer[i];
		buffer[j] = buffer[j] - buffer[i];
	}

	return buffer;
}

int main(int argc, char* argv[])
{
	MYSQL conn;
	int res;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("%d\t%d\n", tv.tv_usec, tv.tv_sec);
	mysql_init(&conn);
	if(mysql_real_connect(&conn,"localhost", "jingsia","kingxinyjx", "asss_yjx_normal", 0, NULL, CLIENT_FOUND_ROWS))
	{
		printf("connect success!\n");

		int i;
		for(i = 0; i < 10000; ++i)
		{
			std::string str1 = "insert into player values(";
			std::string str2 = ",'123456', 234,45)";
			std::string str = str1 + Itoa(i) + str2;
			res=mysql_query(&conn, str.c_str());
			if(res)
			{
				printf("insert error\n");
			}
			else
			{
				printf("insert success\n");
			}
		
		}
		gettimeofday(&tv, NULL);
		printf("%d\t%d\n", tv.tv_usec, tv.tv_sec);
		mysql_close(&conn);
	}

	return 0;
}
