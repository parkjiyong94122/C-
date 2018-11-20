#include<iostream>
#include<cstring>

using namespace std;

/*	���� ó���� ���� ��Ӱ��迡����
���� ���ӿ� ���� ���ǻ���	*/
class AAA
{
public:
	void ShowYou()
	{
		cout << "AAA exception." << endl;
	}
};

class BBB : public AAA
{
public:
	void ShowYou()
	{
		cout << "BBB exception." << endl;
	}
};

class CCC : public BBB
{
public:
	void ShowYou()
	{
		cout << "CCC exception." << endl;
	}
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
	{
		throw BBB();
	}
	else
	{
		throw CCC();
	}

}

//���� Ŭ������ ���� ���� ó��
/*
//���� ó�� Ŭ����
//�߻�Ŭ���� : ���������Լ��� �����  class
//��ü�� ��������ϸ� ������ ������ �߻�.
class Exception
{
public:
	//���������Լ� : body�� ���� �����Լ�
	virtual void ShowExceptionReason() = 0;
	//�����Լ�
	//virtual void ShowExceptionReason()
	//{}

};

//�Ա� ���� ó�� 
class DepositException : public Exception
{
private:
	int deMoney;
public:
	DepositException(int money) : deMoney(money)
	{}
	void ShowExceptionReason()
	{
		cout << "���ܸ޼��� : " << deMoney << "�� �Ա� �Ұ��մϴ�." << endl;
	}
};
//��� ���� ó��
class WithdrawException : public Exception
{
private:
	int balance;		//���� �ܾ�
public:
	WithdrawException(int money) : balance(money)
	{}
	void ShowExceptionReason()
	{
		cout << "���ܸ޼��� : �ܾ� " << balance << ", �ܾ׺���" << endl;
	}
};
//����
class Account
{
private:
	char accNum[50];	//���¹�ȣ
	int balance;		//�����ܾ�
public:
	Account(const char * acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	//�Ա��Լ�
	void Deposit(int money) throw (Exception) //���� throw (DepositException)�� �������� ���� �߰�
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	//����Լ�
	void Withdarw(int money) throw (Exception)
	{
		if (balance < money)
			throw WithdrawException(money);

		balance -= money;
	}
	//�ܾ�����Լ�
	void ShowMyMoney() const
	{
		cout << "�ܾ� : " << balance << endl;
	}
};
*/

//������ ���� ����
/*
void SimpleFuncOne();
void SimpleFuncTwo();
void SimpleFuncThree();
*/


//������ ����(����)
/*
void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;

	cout << "�������� �� : " << num1 / num2 << endl;
	cout << "�������� ������ : " << num1 % num2 << endl;
}
*/


//�迭 �ε��� ������ �����ε�
/*

class BoundCheckIntArray
{
private:
	int *arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}

	int & operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "�迭�� ������ ������ϴ�." << endl;
			exit(1);
		}
		return arr[idx];
	}

	int & operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "�迭�� ������ ������ϴ�." << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

void ShowAllData(const BoundCheckIntArray &ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
	{
		cout << ref[idx] << endl;
	}
}
*/
/*
class Person
{
private:
	char *name;
	int age;
public:
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName)+1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor ! " << endl;
	}
	//���� ���� ������ �ذ�
	Person & operator=(const Person& ref)
	{
		age = ref.age;
		delete[] name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);

		return *this;
	}
};

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{}
	void ShowData()
	{
		cout << num1 << ". " << num2 << endl;
	}
	First& operator=(const First &ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3 , int n4 ) : num3(n3), num4(n4), First(n1, n2)
	{}
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ". " << num4 << endl;
	}
	//���� ������ �����ε�
	Second & operator=(const Second& ref)
	{
		cout << "Second& operator = ()" << endl;
		First::operator=(ref);
		num3 = ref.num3;
		num4 = ref.num4;

		return *this;
	}
};
*/

int main(void)
{
	/*	���� ó���� ���� ��Ӱ��迡����
		���� ���ӿ� ���� ���ǻ���	*/
	try
	{
		ExceptionGenerator(3);	//CCC
		ExceptionGenerator(2);	//BBB
		ExceptionGenerator(1);	//AAA
	}
	catch (CCC &expn)
	{
		cout << "catch(CCC &expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB &expn)
	{
		cout << "catch(BBB &expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA &expn)
	{
		cout << "catch(AAA &expn)" << endl;
		expn.ShowYou();
	}


	// ���� Ŭ������ ���� ���� ó��
	/*
	Account myAcc("110-366-253164", 5000);

	try
	{
		myAcc.Deposit(2000);

		myAcc.Withdarw(3000);
		myAcc.Withdarw(60000);
	}
	catch (Exception & expn)
	{
		expn.ShowExceptionReason();
	}

	myAcc.ShowMyMoney();
	*/


	// ������ ���� ����
	/*	���ܰ� ó������ �ʾƼ� Exception�� main �Լ����� �����ߴµ�,
		main�Լ����� ���� ���ܸ� ó������ ������ terminate�Լ��� ȣ��Ǹ鼭,
		���α׷��� ����ȴ�.
	
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "�����ڵ� : " << expn << endl;
	}
	*/

	//  ���� ó�� - Exception Handling

	// C++ ������ ���� ó��
	//try...	���		���� �߰�
	//catch...	���		���ܸ� catch�ؼ� ó��
	//throw...	���		���� ó���� ����(�ٸ� ������ �ѱ�)
	/*
	int num1, num2;
	cout << "�� ���� ���� �Է� : ";
	cin >> num1 >> num2;	//���� �߻�

	try
	{
		Divide(num1, num2);
		//if (num2 == 0)
		//	throw num2;

			//cout << "�������� �� : " << num1 / num2 << endl;
			//cout << "�������� ������ : " << num1 % num2 << endl;
	}
	catch (const int expn)
	{
		cout << "������"<<expn<<"�� �� �� �����ϴ�. " << endl;
		cout << "���α׷��� �ٽ� ���� �ϼ���. " << endl;
	}
	*/

	// C ������ ���� ó��
	/*
	int num1, num2;
	cout << "�� ���� ���� �Է� : ";
	cin >> num1 >> num2;	//���� �߻� 

	if (num2 == 0)			//���� üũ
	{						//���� ó��
		cout << "������ 0�� �� �� �����ϴ�. " << endl;
		cout << "���α׷��� �ٽ� ���� �ϼ���. " << endl;
	}
	else
	{
		cout << "�������� �� : " << num1 / num2 << endl;
		cout << "�������� ������ : " << num1 % num2 << endl;
	}
	*/


	//�迭 �ε��� ������ �����ε�

	//arrObject[2];
	//arrObject.operator[](2)
	/*
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i];
	}
	*/


	//��� ���迡���� �⺻ ���� ������
	/*
	Second secondOrg(11, 22, 33, 44);
	Second secondCpy(0,0,0,0);

	secondCpy = secondOrg;

	secondCpy.ShowData();
	*/


	/*	���� �������� �����ε�
		- ��������ڿ� ���
	*/
	//����� ���� ü������ Ŭ���� ������ ���ؼ� -> ��������� ���� ����.
	//Point pos1(5, 7);
	//Point pos2 = pos1;	//���������
	//Point pos2(pos1);		//�����Ϸ��� �ڵ带 ����
	//���� �������� ���� - > ���� ���縦 �ؾߵ�.
	//Point pos1(5, 7);
	//Point pos2(9, 10);
	//pos2 = pos1;
	/*
	First firstOrg(111, 222);
	First firstCpy;

	Second secondOrg(111, 222);
	Second secondCpy;

	secondCpy = secondOrg;	// ���� ������ �����ε� ȣ�� 
	secondCpy.ShowData();
	secondOrg.ShowData();
	*/


	/*
	Person man1("lee", 24);
	Person man2("kim", 22);
	
	man2 = man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	*/
	return 0;
}
/*
void SimpleFuncOne(void)
{
	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}
void SimpleFuncTwo(void)
{
	cout << "SimpleFuncTwo(void)" << endl;
	SimpleFuncThree();
}
void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	throw - 1;
}*/