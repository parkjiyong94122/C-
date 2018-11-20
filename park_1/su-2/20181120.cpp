#include<iostream>
#include<cstring>

using namespace std;

/*	예외 처리를 위한 상속관계에서의
예외 위임에 따른 주의사항	*/
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

//예외 클래스를 통한 예외 처리
/*
//예외 처리 클래스
//추상클래스 : 순수가상함수로 선언된  class
//객체를 만들려고하면 컴파일 에러가 발생.
class Exception
{
public:
	//순수가상함수 : body가 없는 가상함수
	virtual void ShowExceptionReason() = 0;
	//가상함수
	//virtual void ShowExceptionReason()
	//{}

};

//입금 예외 처리 
class DepositException : public Exception
{
private:
	int deMoney;
public:
	DepositException(int money) : deMoney(money)
	{}
	void ShowExceptionReason()
	{
		cout << "예외메세지 : " << deMoney << "는 입금 불가합니다." << endl;
	}
};
//출금 예외 처리
class WithdrawException : public Exception
{
private:
	int balance;		//계좌 잔액
public:
	WithdrawException(int money) : balance(money)
	{}
	void ShowExceptionReason()
	{
		cout << "예외메세지 : 잔액 " << balance << ", 잔액부족" << endl;
	}
};
//계좌
class Account
{
private:
	char accNum[50];	//계좌번호
	int balance;		//계좌잔액
public:
	Account(const char * acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	//입금함수
	void Deposit(int money) throw (Exception) //문법 throw (DepositException)는 가독성을 위해 추가
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	//출금함수
	void Withdarw(int money) throw (Exception)
	{
		if (balance < money)
			throw WithdrawException(money);

		balance -= money;
	}
	//잔액출력함수
	void ShowMyMoney() const
	{
		cout << "잔액 : " << balance << endl;
	}
};
*/

//예외의 다중 위임
/*
void SimpleFuncOne();
void SimpleFuncTwo();
void SimpleFuncThree();
*/


//예외의 전달(위임)
/*
void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;

	cout << "나눗셈의 몫 : " << num1 / num2 << endl;
	cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
}
*/


//배열 인덱스 연산자 오버로딩
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
			cout << "배열의 범위를 벗어났습니다." << endl;
			exit(1);
		}
		return arr[idx];
	}

	int & operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "배열의 범위를 벗어났습니다." << endl;
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
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor ! " << endl;
	}
	//얕은 복사 문제점 해결
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
	//대입 연산자 오버로딩
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
	/*	예외 처리를 위한 상속관계에서의
		예외 위임에 따른 주의사항	*/
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


	// 예외 클래스를 통한 예외 처리
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


	// 예외의 다중 위임
	/*	에외가 처리되지 않아서 Exception이 main 함수까지 도달했는데,
		main함수에서 조차 예외를 처리하지 않으면 terminate함수가 호출되면서,
		프로그램이 종료된다.
	
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "예외코드 : " << expn << endl;
	}
	*/

	//  예외 처리 - Exception Handling

	// C++ 에서의 예외 처리
	//try...	블록		예외 발견
	//catch...	블록		예외를 catch해서 처리
	//throw...	블록		예외 처리의 위임(다른 쪽으로 넘김)
	/*
	int num1, num2;
	cout << "두 개의 숫자 입력 : ";
	cin >> num1 >> num2;	//예외 발생

	try
	{
		Divide(num1, num2);
		//if (num2 == 0)
		//	throw num2;

			//cout << "나눗셈의 몫 : " << num1 / num2 << endl;
			//cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
	}
	catch (const int expn)
	{
		cout << "제수는"<<expn<<"이 될 수 없습니다. " << endl;
		cout << "프로그램을 다시 실행 하세요. " << endl;
	}
	*/

	// C 에서의 예외 처리
	/*
	int num1, num2;
	cout << "두 개의 숫자 입력 : ";
	cin >> num1 >> num2;	//예외 발생 

	if (num2 == 0)			//예외 체크
	{						//예외 처리
		cout << "제수는 0이 될 수 없습니다. " << endl;
		cout << "프로그램을 다시 실행 하세요. " << endl;
	}
	else
	{
		cout << "나눗셈의 몫 : " << num1 / num2 << endl;
		cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
	}
	*/


	//배열 인덱스 연산자 오버로딩

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


	//상속 관계에서의 기본 대입 연산자
	/*
	Second secondOrg(11, 22, 33, 44);
	Second secondCpy(0,0,0,0);

	secondCpy = secondOrg;

	secondCpy.ShowData();
	*/


	/*	대입 연산자의 오버로딩
		- 복사생성자와 비슷
	*/
	//상속의 이유 체계적인 클래스 관리를 위해서 -> 결과적으로 재사용 가능.
	//Point pos1(5, 7);
	//Point pos2 = pos1;	//복사생성자
	//Point pos2(pos1);		//컴파일러가 코드를 변경
	//복사 생성자의 단점 - > 깊은 복사를 해야됨.
	//Point pos1(5, 7);
	//Point pos2(9, 10);
	//pos2 = pos1;
	/*
	First firstOrg(111, 222);
	First firstCpy;

	Second secondOrg(111, 222);
	Second secondCpy;

	secondCpy = secondOrg;	// 대입 연산자 오버로딩 호출 
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