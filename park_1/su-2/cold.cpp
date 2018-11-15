#include<cstring>
#include"coldpatient.h"

using namespace std;

//소멸자
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
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
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