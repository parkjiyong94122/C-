#include<cstring>
#include"coldpatient.h"

using namespace std;

//�Ҹ���
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
	void SetPersonInfo(char* MyName, int MyAge)
	{
		name = MyName;
		age = MyAge;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "destructor called!!" << endl;
	}
};



int main(void)
{
	
	
	return 0;
}