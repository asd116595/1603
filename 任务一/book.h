#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct people//认得结构体
{
	int num, age, phone, telphone;//结构体里的变量
	string name;
	char sex;
	people *next;
};
class book
{private://Txl的私有成员函数
	friend istream& operator >> (istream&, people&);//多态
	friend ostream& operator << (ostream&, people&);
	people *insertP(people *head);
	people *addP(people *head);
	people *updataP(people *head);
	people *deleteP(people *head);
	void outputP(people *head);
	void drP(people *head);
	void findP(people *head);
	people* dcP(people *head);
public:
	book();
	~book();
	void menu();
};

