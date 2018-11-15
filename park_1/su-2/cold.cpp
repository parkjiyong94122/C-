#include<cstring>
#include"coldpatient.h"

using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() called!" << endl;
	}
	Person(const char* MyName, int MyAge )
	{
		int len = strlen(MyName)+1;
		name = new char[len];
		strcpy(name, MyName);
		age = MyAge;
	}
	Person(const Person &copy) : age(copy.age)	
	{
		//���� ����
		name = new char[strlen(copy.name)+1];
		strcpy(name, copy.name);
	}
	void SetPersonInfo(char* MyName, int MyAge)
	{
		name = MyName;
		age = MyAge;
	}

	void WhatYoutName() const
	{
		cout << "�̸� : " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "���� : " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "destructor called!!" << endl;
	}
};

//���� ������ ������ �߻��ϴ� Ÿ�̹� : 
// 1. "="  man = man2 
// 2. call by value ����� �Լ� ȣ��������� ��ü�� ���ڷ� ������ ��
// 3. ��ü�� return �� �� ���������� ��ȯ���� ���� ���

int main(void)
{
	// ���� ���� (shallow copy)
	Person man("Lee", 25);
	Person man2 = man;
	//'man2 = man' ���� "Lee" ����� �ּҸ� �����ϱ� ������ 2���� delete�� �߻��Ͽ� �޸� ���� �߻�.

	man2.HowOldAreYou();
	man2.WhatYoutName();
	
	return 0;
}