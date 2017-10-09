/*************************************************************************
	> File Name: b.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 10 Oct 2017 12:07:31 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
struct student{
	char name[10];
	int score;
	int age;
};
#if 0
//自定义“小于”
bool comp(const student &a, const student &b)
{
	if (a.score > b.score)
		return true;
	else if (a.score == b.score  && a.age > b.age)
		return true;
	else                ///这里的else return false非常重要！！！！！
		return false;
}

int main(){
	vector<student> vectorStudents;
	/*set<student> setStudents;*/
	//int n = 5;
	int n = 3;
	while (n--){
		student oneStudent;
		string name;
		int score;
		int age;
		cin >> name >> score>>age;
		strcpy(oneStudent.name, name.c_str());
		oneStudent.score = score;
		oneStudent.age = age;
		vectorStudents.push_back(oneStudent);
	}
	cout << "===========排序前================" << endl;
	for (vector<student>::iterator it = vectorStudents.begin(); it != vectorStudents.end(); it++){
		cout << "name: " << it->name << " score: " << it->score << " age: "<<it->age<<endl;
	}
	sort(vectorStudents.begin(), vectorStudents.end(), comp);
	//sort(setStudents.begin(), setStudents.end());
	cout << "===========排序后================" << endl;
	for (vector<student>::iterator it = vectorStudents.begin(); it != vectorStudents.end(); it++){
		cout << "name: " << it->name << " score: " << it->score << " age: " << it->age << endl;
	}
	return 0;
}
#endif

//自定义“小于”
struct comp_sort
{
	bool operator()(const student &a, const student &b)
	{
		if (a.score > b.score)
			return true;
		else if (a.score == b.score  && a.age > b.age)
			return true;
		else                ///这里的else return false非常重要！！！！！
			return false;
	}

};

int main(){
	//vector<student, comp_sort> vectorStudents;
	typedef std::multiset<student, comp_sort> StudentType;
	StudentType testStudents;
	//int n = 5;
	int n = 3;
	while (n--){
		student oneStudent;
		string name;
		int score;
		int age;
		cin >> name >> score>>age;
		strcpy(oneStudent.name, name.c_str());
		oneStudent.score = score;
		oneStudent.age = age;
		testStudents.insert(oneStudent);
	}
	cout << "===========排序前================" << endl;
	for (StudentType::iterator it = testStudents.begin(); it != testStudents.end(); it++){
		cout << "name: " << it->name << " score: " << it->score << " age: "<<it->age<<endl;
	}
	//sort(vectorStudents.begin(), vectorStudents.end(), comp);
	//sort(setStudents.begin(), setStudents.end());
	cout << "===========排序后================" << endl;
	for (StudentType::iterator it = testStudents.begin(); it != testStudents.end(); it++){
		cout << "name: " << it->name << " score: " << it->score << " age: " << it->age << endl;
	}
	return 0;
}
