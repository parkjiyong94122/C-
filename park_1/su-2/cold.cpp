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
	//매개변수가 없는 constructor 생성자도 오버로딩 가능
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() called!" << endl;
	}
	//매개변수가 있는 constructor 생성자
	Person(const char* MyName, int MyAge )
	{
		int len = strlen(MyName)+1;
		name = new char[len];
		strcpy(name, MyName);
		age = MyAge;
	}
	//멤버 변수 수정 함수
	void SetPersonInfo(char* MyName, int MyAge)
	{
		name = MyName;
		age = MyAge;
	}

	//출력함수
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	//destructor소멸자
	~Person()
	{
		delete[]name;
		cout << "destructor called!!" << endl;
	}
};


//this pointer

//과제 2번

int main(void)
{
	//객체배열
	/*
	Person personArr[3];

	char namestr[100];
	char * strptr;
	int age;
	int len;


	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		personArr[i].SetPersonInfo(strptr, age);
	}

	personArr[0].ShowPersonInfo();
	personArr[1].ShowPersonInfo();
	personArr[2].ShowPersonInfo();
	*/

	//객체 포인터 배열
	/*
	Person* personPArr[3];

	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;

		personPArr[i] = new Person(namestr,age); //new의 리턴값은 Person 객체의 주소값을 출력
	}

	personPArr[0]->ShowPersonInfo();
	personPArr[1]->ShowPersonInfo();
	personPArr[2]->ShowPersonInfo();
	
	//new 사용시 delete사용
	delete personPArr[0];
	delete personPArr[1];
	delete personPArr[2];
	*/

	//소멸자
	/*
	Person man1("park", 25);
	Person man2("kim", 21);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	*/
	//범위
	/*
	ColdPatient patient;
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;
	AllCap acap;


	//patient.TakeSinivelCap(scap);
	//patient.TakeSneezeCap(zcap);
	//patient.TakeSnuffleCap(ncap);

	//patient.TakeCap(acap);
	*/

	
	return 0;
}