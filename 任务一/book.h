#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct people//�ϵýṹ��
{
	int num, age, phone, telphone;//�ṹ����ı���
	string name;
	char sex;
	people *next;
};
class book
{private://Txl��˽�г�Ա����
	friend istream& operator >> (istream&, people&);//��̬
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

