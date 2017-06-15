/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Thu 15 Jun 2017 05:55:08 PM CST
 ************************************************************************/
//将字符串取到后几位 定义字符串内容为16进制 16进制转10进制内容
#include<iostream>
#include<cstring>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

inline string getStringLastNChar(string str, int lastN)
{
	return str.substr(str.size() - lastN);
}

int GetStrIntSix(std::string str)
{
	const char *k = str.c_str();
	return strtol(k, NULL, 16);
}

int main()
{
	std::string str = "081234abcf1";
	std::string sss = "0x" + getStringLastNChar(str, 2);
	printf("%d", GetStrIntSix(sss));
	return 0;
}
