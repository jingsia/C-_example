/*************************************************************************
	> File Name: main.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 13 Dec 2017 05:32:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include "MyDB.h"

int main()
{
	MyDB db;
	db.initDB("localhost", "jingsia", "kingxinyjx", "asss_yjx_normal");
	db.exeSQL("select * from player");

	return 0;
}
