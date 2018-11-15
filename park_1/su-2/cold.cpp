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
		//깊은 복사
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
		cout << "이름 : " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "destructor called!!" << endl;
	}
};

//얕은 복사의 문제가 발생하는 타이밍 : 
// 1. "="  man = man2 
// 2. call by value 방식의 함수 호출과정에서 객체를 인자로 전달할 때
// 3. 객체를 return 할 때 참조형으로 반환하지 않은 경우

int main(void)
{
	// 얕은 복사 (shallow copy)
	Person man("Lee", 25);
	Person man2 = man;
	//'man2 = man' 에서 "Lee" 멤버의 주소를 저장하기 때문에 2번의 delete가 발생하여 메모리 오류 발생.

	man2.HowOldAreYou();
	man2.WhatYoutName();
	
	return 0;
}