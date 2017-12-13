/*************************************************************************
	> File Name: MyDB.h
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 13 Dec 2017 05:14:54 PM CST
 ************************************************************************/
#ifndef MYDB
#define MYDB

#include<iostream>
using namespace std;
#include<string>
#include<mysql/mysql.h>

class MyDB
{
	public:
		MyDB();
		~MyDB();

		bool initDB(string host, string user, string pwd, string db_name);
		bool exeSQL(string sql);

	private:
		MYSQL *connection;
		MYSQL_RES *result;
		MYSQL_ROW row;
		MYSQL_FIELD* field = NULL;
};

#endif
