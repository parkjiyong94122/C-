#include <iostream>
#include <cstring>
#include <stdlib.h>

char * MakeStrAdtr(int len)
{
	//char * str = (char *)malloc(sizeof(char)*len);
	char * str = new char[len];
	return str;
}

//#define SQUARE(x) ((x)*(x))

template <typename T>

//템플릿 원하는 자료형으로 변경가능
inline T SQUARE(T x)
{
	return x * x;
}

using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num;
			int num2;
		}
	}
}

namespace BestComImpl {
	void SimpleFunc(void);
}
namespace ProgComImpl {
	void SimpleFunc(void);
}



int adder(int num1 = 1, int num2 = 2);


void MyFunc(void)
{
	cout << "MyFunc(void) Called " << endl;
}
void MyFunc(char c)
{
	cout << "MyFunc(char c) Called " << endl;
}
void MyFunc(int a , int b)
{
	cout << "MyFunc(int a, int b) Called " << endl;
}

int main(void)
{ 

	char * str = MakeStrAdtr(20);
	strcpy_s(str, "I am happy!.");
	cout << str << endl;
	delete[]str;
	/* boolean
	cout << "true : " << sizeof(true) << endl;
	cout << "false : " << false << endl;
	*/
	/* 인라인 함수호출부가 함수바디로  C++ 인라인함수 제공
		C++에서 주는 매크로함수를 대용가능하게함
	
	cout << SQUARE(3.3) << endl;
	cout << SQUARE(3) << endl;
	*/

	/* name space - 2

	AAA::BBB::CCC::num = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;

	cout << ABC::num <<endl<< ABC::num2 <<endl;
	*/

	/* name space - 1
	
	using BestComImpl::SimpleFunc;
	SimpleFunc();
	ProgComImpl::SimpleFunc();
	*/


	/*default 매개변수
	cout << "1+2" << adder();
	cout << "2+3" << adder(2, 3);
	*/

	/* 함수 오버로딩
	MyFunc();
	MyFunc('a');
	MyFunc(2,1);
	*/
	/*
	char name[100];
	char lang[200];

	cout << "이름을 입력해주세요 :  ";
	cin >> name;

	cout << "좋아하는 언어 입력 :  ";
	cin >> lang;

	cout << name << lang << endl;
	*/

	/*
	int val;

	cout << "1번째 숫자 입력 :  ";
	cin >> val;
	
	int val2;

	cout << "2번째 숫자 입력 :  ";
	cin >> val2;

	int result = val + val2;

	cout << result;
	*/
	/*
	int num = 20;
	cout << "hello world!!~" << endl;
	cout << "hello " << "world " << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;
	*/
	

	return 0;
}

void BestComImpl::SimpleFunc(void)
{
	cout << "BestCom의 함수." << endl;
}

void ProgComImpl::SimpleFunc(void)
{
	cout << "ProgCom의 함수." << endl;
}

int adder(int num1, int num2)
{
	return num1 + num2;
}