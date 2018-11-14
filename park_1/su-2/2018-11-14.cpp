#include<iostream>
#include<cstring>

using namespace std;

/*
	- �������� ����̴�.
	- �����,������ ������ �� �ֵ��� Ŭ������ �������ϼ���
	- ����� ������ �� �ִ� Ŭ������ ������.
	- ������ �λ���� ���α׷��� �ۼ��ϼ���.
*/

//������ ���� ������. has A 
class Gun
{
private:
	int bullet;
public:
	Gun(int bulletNum) : bullet(bulletNum)
	{}
	void Shot()
	{
		cout << "BANG~~!" << endl;
		bullet--;
	}
};

//has a ������ police class
class Police 
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int handcuffsNum, int bulletNum) : handcuffs(handcuffsNum)
	{
		if (bulletNum > 0)
			pistol = new Gun(bulletNum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol != NULL)
			pistol->Shot();
		else
			cout << "bullet emety" << endl;
		
	}
	~Police()
	{
		if(pistol != NULL)
			delete pistol;
	}
};

// is a ������ police class
/*
class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int handcuffsNum, int bulletNum) : Gun(bulletNum), handcuffs(handcuffsNum)
	{}
	void PutHandcuff()
	{
		cout << "SNAP!!" << endl;
		handcuffs--;
	}
};
*/

// �л��� ����̴�. is A
/*
class person
{
private:
	char name[50];
	int age;
public:
	person(int myAge, const char* myName) : age(myAge)
	{
		//this->age = myAge;
		strcpy(name, myName);
	}
	void WhatYourName() const
	{
		cout << "My name is  " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << "years old" << endl;
	}
};
class Student : public person
{
private:
	char major[50];
public:
	Student(int myAge,const char* myName, const char* myMajor) : person(myAge, myName)
	{
		strcpy(major, myMajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is" << major << endl;
	}
};
*/
int main(void)
{
	// ���
	/*
		- ����
			Ŭ���� ���� ���踦 ü�������� ���� �� �����ϱ� ���ؼ��̴�.
			(����)
		- ���谡 �������� ������ �Ǿ�� ����̶�� ���� �� �ִ�.

		- is A ����
		ex) ��Ʈ���� ��ǻ�� �̴�
		    notebook is computer.

		- has A ����
		ex) ������ ���� ������.
			police has a gun.
	*/
	// �л��� ����̴�. is A
	/*
	Student stu1(22, "Lee", "computer Eng.");
	stu1.WhoAreYou();

	Student stu2(20, "Yoon", "Electronic Eng.");
	stu2.HowOldAreYou();
	stu2.WhatYourName();
	stu2.WhoAreYou();
	*/
	// ������ ���� ������. has A
	Police policeMan(5, 3);
	policeMan.Shot();
	policeMan.PutHandcuff();
	
	//���� ����
	Police trafficPolice(3, 0);
	trafficPolice.Shot();
	trafficPolice.PutHandcuff();


	return 0;
}