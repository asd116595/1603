#include "book.h"//����Txl.h�ļ�
void main()
{
	book t;//����һ��Txl����
	t.menu();//���øö���Ĳ˵�����
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
people* book::insertP(people *head)//��������ʼ����
{
	head = NULL;
	cout << "���Դ��´�����ͨѶ¼������" << endl;
	return head;
}
people* book::addP(people *head)//���ͨѶ¼�����Ϣ
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
	newP = new people;//����һ���ṹ�����
	if (newP == NULL)
	{
		cout << "No memory available!" << endl;
		return head;
	}
	cout << "��������Ҫ����˵���Ϣ����š��������Ա����䡢լ�硢�ֻ��绰����" << endl;
	cin >> *newP;
	while (curP1)//�ж��������Ϣ�Ƿ���ͨѶ¼�����Ϣ�г�ͻ
	{
		if ( newP->telphone == curP1->telphone)
		if (newP->sex == curP1->sex && newP->age == curP1->age)
		{
			if ( newP->num == curP1->num || newP->phone == curP1->phone )
			{
				cout << "���������Ϣ��ͨѶ¼�����е�"<<curP1->name<<"����Ϣ�г�ͻ������" << endl;
				cout << "���ʧ�ܣ�����" << endl;
				return head;
			}
		}
		curP1 = curP1->next;
	}//����ӵ���Ϣ�ӵ�������
	if (preP == NULL) 
	{
		newP->next = curP;
		cout << "���Գɹ������˵���Ϣ��ӵ�ͨѶ¼�У�������" << endl;
		return newP;
	}
	else  {
		preP->next = newP;
		newP->next = curP;
		cout << "���Գɹ������˵���Ϣ��ӵ�ͨѶ¼�У�������" << endl;
		return head;
	}
	
}
void book::findP(people *head)
{
	cout << "&* 1.��������ѯ 2.���ֻ���ѯ *&" << endl;
	cout<<endl<< "��ѡ��";
	people *curP = head;
	int x;
	cin >> x;
	if (x == 1)
	{
		string n;
		cout << "����������Ҫ��ѯ���˵�������";
		cin >> n;
		while (curP)
		{
			if (curP->name ==n )
			{
				cout << "|���|����|�Ա�|����|լ��|�ֻ��绰|" << endl;
				cout << *curP<<endl;
				return;
			}
			curP = curP->next;
		}
		cout << "���ͨѶ¼��û�и��˵���Ϣ������" << endl;
	}
	else
	{
		int n;
		cout << "����������Ҫ��ѯ���˵��ֻ����룺";
		cin >> n;
		while (curP)
		{
			if (curP->telphone == n)
			{
				cout << "|���|����|�Ա�|����|լ��|�ֻ��绰|" << endl;
				cout << *curP << endl;
				return;
			}
			curP = curP->next;
		}
		cout << "���ͨѶ¼��û�и��˵���Ϣ������" << endl;
	}
}
people* book::updataP(people *head)
{
	cout << "����������Ҫ�޸ĵ��˵�������";
	string n;
	cin >> n;
	people *curP = head;
	while (curP)
	{
		if (curP->name == n)
		{
			cout << "������" << n << "��������Ϣ����š��������Ա����䡢լ�硢�ֻ��绰����" << endl;
			cin >> *curP;
			return head;
		}
		curP = curP->next;
	}
	cout << "���ͨѶ¼��û�и��˵���Ϣ������" << endl;
	return head;
}
people* book::deleteP(people *head)
{
	cout << "&* 1.������ɾ�� 2.�����ɾ�� *&" << endl;
	cout << endl << "��ѡ��";
	people *curP = head;
	people *preP = NULL; 
	int x;
	cin >> x;
	if (x == 1)
	{
		string n;
		cout << "����������Ҫɾ�����˵�������";
		cin >> n;
		while (curP&&curP->name != n)
		{
			preP = curP;
			curP = curP->next;
		}
		if (preP == NULL)//ɾ���Ľڵ�Ϊ�׽ڵ�
		{
			head = head->next;
			cout << "���Գɹ�ɾ��" << n << "����Ϣ������" << endl;
			return head;
		}
		if(preP!=NULL&&curP!=NULL)//ɾ���Ĳ����׽ڵ�ǰ�ڵ��nextָ��ǰ�ڵ��next����ָ���ڵ�
		{
			preP->next = curP->next;
			delete curP;
			cout << "���Գɹ�ɾ��" << n << "����Ϣ������" << endl;
			return head;
		}
		cout << "���ͨѶ¼��û�и��˵���Ϣ������" << endl;
		return head;
	}
	else
	{
		int n;
		cout << "����������Ҫɾ�����˵ı�ţ�";
		cin >> n;
		while (curP&&curP->num != n)
		{
			preP = curP;
			curP = curP->next;
		}
		if (preP == NULL)//ɾ���Ľڵ�Ϊ�׽ڵ�
		{
			head = head->next;
			cout << "���Գɹ�ɾ�����Ϊ" << n << "����Ϣ������" << endl;
			return head;
		}
		if (preP != NULL&&curP != NULL)//ɾ���Ĳ����׽ڵ�ǰ�ڵ��nextָ��ǰ�ڵ��next����ָ���ڵ�
		{
			preP->next = curP->next;
			delete curP;
			cout << "���Գɹ�ɾ�����Ϊ" << n << "����Ϣ������" << endl;
			return head;
		}
		cout << "���ͨѶ¼��û�и��˵���Ϣ������" << endl;
		return head;
	}
}
void book::outputP(people *head)
{
	cout << "ͨѶ¼��"<<endl;
	cout << "|���|����|�Ա�|����|լ��|�ֻ��绰|" << endl;
	people *curP = head;
	if (curP == NULL)cout << "���ͨѶ¼��û����Ϣ������" << endl;
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
		cout << "�㵼�����һ���յ�ͨѶ¼������" << endl;
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
	
	cout << "���ѳɹ����룡����" << endl;
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
	cout << "���ѳɹ�����������" << endl;
	return head;
}
void book::menu()
{
	people *ListHead=NULL;
	cout << "��ѡ�������һ����Ŀ��" << endl;//���˵�
	cout << "**********************" << endl;
	cout << "1.����  2.���  3.��ѯ" << endl;
	cout << "4.�޸�  5.ɾ��  6.��ʾ" << endl;
	cout << "7.�ļ�����  8.�ļ�����" << endl;
	cout << "9 �˳�" << endl;
	cout << "**********************" << endl;
	cout << "��ѡ��";
	int m;
	cin >> m;
	while (m != 9)
	{
		switch (m)//switch ���
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
		cout << "��ѡ�������һ����Ŀ��" << endl;
		cout << "**********************" << endl;
		cout << "1.����  2.���  3.��ѯ" << endl;
		cout << "4.�޸�  5.ɾ��  6.��ʾ" << endl;
		cout << "7.�ļ�����  8.�ļ�����" << endl;
		cout << "9 �˳�" << endl;
		cout << "**********************" << endl;
		cout << "��ѡ��";
		cin >> m;
	}
}
