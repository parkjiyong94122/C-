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
	//�Ű������� ���� constructor �����ڵ� �����ε� ����
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() called!" << endl;
	}
	//�Ű������� �ִ� constructor ������
	Person(const char* MyName, int MyAge )
	{
		int len = strlen(MyName)+1;
		name = new char[len];
		strcpy(name, MyName);
		age = MyAge;
	}
	//��� ���� ���� �Լ�
	void SetPersonInfo(char* MyName, int MyAge)
	{
		name = MyName;
		age = MyAge;
	}

	//����Լ�
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	//destructor�Ҹ���
	~Person()
	{
		delete[]name;
		cout << "destructor called!!" << endl;
	}
};


//this pointer

//���� 2��

int main(void)
{
	//��ü�迭
	/*
	Person personArr[3];

	char namestr[100];
	char * strptr;
	int age;
	int len;


	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
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

	//��ü ������ �迭
	/*
	Person* personPArr[3];

	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		personPArr[i] = new Person(namestr,age); //new�� ���ϰ��� Person ��ü�� �ּҰ��� ���
	}

	personPArr[0]->ShowPersonInfo();
	personPArr[1]->ShowPersonInfo();
	personPArr[2]->ShowPersonInfo();
	
	//new ���� delete���
	delete personPArr[0];
	delete personPArr[1];
	delete personPArr[2];
	*/

	//�Ҹ���
	/*
	Person man1("park", 25);
	Person man2("kim", 21);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	*/
	//����
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