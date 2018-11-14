#include<iostream>
#include<cstring>

using namespace std;

/*
	- 정규직은 사원이다.
	- 사원명,월급을 관리할 수 있도록 클래스를 디자인하세요
	- 사원을 관리할 수 있는 클래스를 디자인.
	- 간단한 인사관리 프로그램을 작성하세요.
*/

//경찰은 총을 가진다. has A 
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

//has a 관계의 police class
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

// is a 관계의 police class
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

// 학생은 사람이다. is A
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
	// 상속
	/*
		- 목적
			클래스 간의 관계를 체계적으로 유지 및 관리하기 위해서이다.
			(재사용)
		- 관계가 논리적으로 성립이 되어야 상속이라고 말할 수 있다.

		- is A 관계
		ex) 노트북은 컴퓨터 이다
		    notebook is computer.

		- has A 관계
		ex) 경찰은 총을 가진다.
			police has a gun.
	*/
	// 학생은 사람이다. is A
	/*
	Student stu1(22, "Lee", "computer Eng.");
	stu1.WhoAreYou();

	Student stu2(20, "Yoon", "Electronic Eng.");
	stu2.HowOldAreYou();
	stu2.WhatYourName();
	stu2.WhoAreYou();
	*/
	// 경찰은 총을 가진다. has A
	Police policeMan(5, 3);
	policeMan.Shot();
	policeMan.PutHandcuff();
	
	//교통 경찰
	Police trafficPolice(3, 0);
	trafficPolice.Shot();
	trafficPolice.PutHandcuff();


	return 0;
}