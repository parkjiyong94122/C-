#include <iostream>
using namespace std;


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

	/* name space
	BestComImpl::SimpleFunc();
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