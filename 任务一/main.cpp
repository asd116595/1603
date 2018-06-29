#include "book.h"//调用Txl.h文件
void main()
{
	book t;//定义一个Txl对象
	t.menu();//调用该对象的菜单函数
}
book::book()
{
}
book::~book()
{
}
istream& operator >> (istream& input, people& C)
{
	input >> C.num>> C.name>>C.sex>>C.age>>C.phone>>C.telphone;
	return input;
}
ostream& operator << (ostream& output, people& C)
{
	output << C.num << " " << C.name << " " << C.sex << " " << C.age << " " << C.phone  << " "<<C.telphone;
	return output;
}
people* book::insertP(people *head)//创建（初始化）
{
	head = NULL;
	cout << "你以从新创建了通讯录！！！" << endl;
	return head;
}
people* book::addP(people *head)//添加通讯录里的信息
{
	people * curP = head;
	people *preP = NULL;
	people * newP = NULL;
	people *curP1 = head;
	while (curP)
	{
		preP = curP;
		curP = curP->next;
	}
	newP = new people;//定义一个结构体变量
	if (newP == NULL)
	{
		cout << "No memory available!" << endl;
		return head;
	}
	cout << "请输入你要添加人的信息（编号、姓名、性别、年龄、宅电、手机电话）：" << endl;
	cin >> *newP;
	while (curP1)//判断输入的信息是否与通讯录里的信息有冲突
	{
		if ( newP->telphone == curP1->telphone)
		if (newP->sex == curP1->sex && newP->age == curP1->age)
		{
			if ( newP->num == curP1->num || newP->phone == curP1->phone )
			{
				cout << "你输入的信息和通讯录中已有的"<<curP1->name<<"的信息有冲突！！！" << endl;
				cout << "添加失败！！！" << endl;
				return head;
			}
		}
		curP1 = curP1->next;
	}//将添加的信息接到链表上
	if (preP == NULL) 
	{
		newP->next = curP;
		cout << "你以成功将该人的信息添加到通讯录中！！！！" << endl;
		return newP;
	}
	else  {
		preP->next = newP;
		newP->next = curP;
		cout << "你以成功将该人的信息添加到通讯录中！！！！" << endl;
		return head;
	}
	
}
void book::findP(people *head)
{
	cout << "&* 1.按姓名查询 2.按手机查询 *&" << endl;
	cout<<endl<< "请选择：";
	people *curP = head;
	int x;
	cin >> x;
	if (x == 1)
	{
		string n;
		cout << "请输入你想要查询的人的姓名：";
		cin >> n;
		while (curP)
		{
			if (curP->name ==n )
			{
				cout << "|编号|姓名|性别|年龄|宅电|手机电话|" << endl;
				cout << *curP<<endl;
				return;
			}
			curP = curP->next;
		}
		cout << "你的通讯录里没有该人的信息！！！" << endl;
	}
	else
	{
		int n;
		cout << "请输入你想要查询的人的手机号码：";
		cin >> n;
		while (curP)
		{
			if (curP->telphone == n)
			{
				cout << "|编号|姓名|性别|年龄|宅电|手机电话|" << endl;
				cout << *curP << endl;
				return;
			}
			curP = curP->next;
		}
		cout << "你的通讯录里没有该人的信息！！！" << endl;
	}
}
people* book::updataP(people *head)
{
	cout << "请输入你想要修改的人的姓名：";
	string n;
	cin >> n;
	people *curP = head;
	while (curP)
	{
		if (curP->name == n)
		{
			cout << "请输入" << n << "的最新信息（编号、姓名、性别、年龄、宅电、手机电话）：" << endl;
			cin >> *curP;
			return head;
		}
		curP = curP->next;
	}
	cout << "你的通讯录里没有该人的信息！！！" << endl;
	return head;
}
people* book::deleteP(people *head)
{
	cout << "&* 1.按姓名删除 2.按编号删除 *&" << endl;
	cout << endl << "请选择：";
	people *curP = head;
	people *preP = NULL; 
	int x;
	cin >> x;
	if (x == 1)
	{
		string n;
		cout << "请输入你想要删除的人的姓名：";
		cin >> n;
		while (curP&&curP->name != n)
		{
			preP = curP;
			curP = curP->next;
		}
		if (preP == NULL)//删除的节点为首节点
		{
			head = head->next;
			cout << "你以成功删除" << n << "的信息！！！" << endl;
			return head;
		}
		if(preP!=NULL&&curP!=NULL)//删除的不是首节点前节点的next指向当前节点的next，即指向后节点
		{
			preP->next = curP->next;
			delete curP;
			cout << "你以成功删除" << n << "的信息！！！" << endl;
			return head;
		}
		cout << "你的通讯录里没有该人的信息！！！" << endl;
		return head;
	}
	else
	{
		int n;
		cout << "请输入你想要删除的人的编号：";
		cin >> n;
		while (curP&&curP->num != n)
		{
			preP = curP;
			curP = curP->next;
		}
		if (preP == NULL)//删除的节点为首节点
		{
			head = head->next;
			cout << "你以成功删除编号为" << n << "的信息！！！" << endl;
			return head;
		}
		if (preP != NULL&&curP != NULL)//删除的不是首节点前节点的next指向当前节点的next，即指向后节点
		{
			preP->next = curP->next;
			delete curP;
			cout << "你以成功删除编号为" << n << "的信息！！！" << endl;
			return head;
		}
		cout << "你的通讯录里没有该人的信息！！！" << endl;
		return head;
	}
}
void book::outputP(people *head)
{
	cout << "通讯录："<<endl;
	cout << "|编号|姓名|性别|年龄|宅电|手机电话|" << endl;
	people *curP = head;
	if (curP == NULL)cout << "你的通讯录里没有信息！！！" << endl;
	while (curP)
	{
		cout << *curP << endl;
		curP = curP->next;
	}
}
void book::drP(people *head)
{
	ofstream outfile("f1.txt", ios::out);
	if (!outfile)
	{
		cerr << "Open error!";
		exit(1);
	}
	if (head == NULL)
	{
		cout << "你导入的是一个空的通讯录！！！" << endl;
		outfile.close();
		return;
	}
	people *curP = head;
	outfile <<" " << *curP << endl;
	curP = curP->next;
	while (curP)
	{
		outfile<<" " << *curP << endl;
		curP = curP->next;
	}
	outfile.close();
	
	cout << "你已成功导入！！！" << endl;
}
people* book::dcP(people *head)
{
	ifstream infile("f1.txt", ios::in);
	if (!infile)
	{
		cerr << "Open error!";
		exit(1);
		return head;
	}
	people * curP = head;
	people *preP = NULL;
	people * newP = NULL;
	
	char c; 
loop:infile.get(c);
    if (c == ' ')
	{
		while (curP)
		{
			preP = curP;
			curP = curP->next;
		}
	newP = new people;
		if (newP == NULL)
		{
			cout << "No memory available!" << endl;
			infile.close();
			return head;
		}
		infile >> *newP;
		if (preP == NULL)
		{
			newP->next = curP;
			head = newP;
			curP = newP;
		}
		else  {
			preP->next = newP;
			newP->next = curP;
			curP = head;
		}
	}
	if(!infile.eof())goto loop;
	infile.close();
	cout << "你已成功导出！！！" << endl;
	return head;
}
void book::menu()
{
	people *ListHead=NULL;
	cout << "请选择下面的一个项目：" << endl;//主菜单
	cout << "**********************" << endl;
	cout << "1.创建  2.添加  3.查询" << endl;
	cout << "4.修改  5.删除  6.显示" << endl;
	cout << "7.文件导入  8.文件导出" << endl;
	cout << "9 退出" << endl;
	cout << "**********************" << endl;
	cout << "请选择：";
	int m;
	cin >> m;
	while (m != 9)
	{
		switch (m)//switch 语句
		{
		case 1:ListHead=insertP(ListHead); break;
		case 2:ListHead = addP(ListHead); break;
		case 3:findP(ListHead); break;
		case 4:ListHead = updataP(ListHead); break;
		case 5:ListHead = deleteP(ListHead); break;
		case 6:outputP(ListHead); break;
		case 7:drP(ListHead); break;
		case 8:ListHead=dcP(ListHead); break;
		}
		cout << "请选择下面的一个项目：" << endl;
		cout << "**********************" << endl;
		cout << "1.创建  2.添加  3.查询" << endl;
		cout << "4.修改  5.删除  6.显示" << endl;
		cout << "7.文件导入  8.文件导出" << endl;
		cout << "9 退出" << endl;
		cout << "**********************" << endl;
		cout << "请选择：";
		cin >> m;
	}
}
