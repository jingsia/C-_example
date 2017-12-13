/*************************************************************************
	> File Name: MyDB.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Wed 13 Dec 2017 05:16:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include "MyDB.h"
#include <cstdlib>

MyDB::MyDB()
{
	connection = mysql_init(NULL);
	if(connection == NULL)
	{
		cout << "ERROR : " << mysql_error(connection);
		exit(1);
	}
}

MyDB::~MyDB()
{
	if(connection != NULL)
	{
		mysql_close(connection);
	}
}

bool MyDB::initDB(string host, string user, string pwd, string db_name)
{
	connection = mysql_real_connect(connection, host.c_str(), user.c_str(), pwd.c_str(), db_name.c_str(), 0, NULL, 0);
	if(connection == NULL)
	{
		cout << "ERROR : " << mysql_error(connection);
		exit(1);
	}

	return true;
}

/*
 * 通过 mysql_real_query 查询后，
 * 调用 mysql_store_result 取得结果，
 * mysql_num_rows 取得行数，
 * 循环调用 mysql_fetch_row 可以取到每一行记录，假设变量为 row，
 * 每一行记录是一个 char ** 型，取第 0 列则为 row[0], 它是一个 char * 型，要转成目标类型的话，可以使用其他函数，如 atoi, atol, atof 等等。
 * mysql_free_result 函数用于释放结果集。
 * 至于以上各个函数的用法，你可以在网上再查找具体的函数原型及用法。
 * */

bool MyDB::exeSQL(string sql)
{
	cout << sql << std::endl;
	if(mysql_query(connection, sql.c_str()))
	{
		cout << "QUERY ERROR : " << mysql_error(connection);
		exit(1);
	}
	else
	{
		//result = mysql_use_result(connection);
		result = mysql_store_result(connection);

		for(int i=0; i<mysql_num_fields(result); i++)
		{         
			field = mysql_fetch_field_direct(result,i);
			cout << field->name << "\t\t";
		}                
		cout << endl;

		cout << "field==>" << mysql_field_count(connection) << endl;
		cout << "mysql_num_rows()==>" << mysql_num_rows(result) << std::endl;

		for(int i = 0; i < mysql_num_rows(result); ++i)
		{
			row = mysql_fetch_row(result);
			for(int j = 0; j < mysql_num_fields(result); ++j)
			{
				cout << row[j] << " ";
			}
			cout << endl;
		}

		mysql_free_result(result);
	}
	return true;
}

