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

//���ø� ���ϴ� �ڷ������� ���氡��
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
	/* �ζ��� �Լ�ȣ��ΰ� �Լ��ٵ��  C++ �ζ����Լ� ����
		C++���� �ִ� ��ũ���Լ��� ��밡���ϰ���
	
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


	/*default �Ű�����
	cout << "1+2" << adder();
	cout << "2+3" << adder(2, 3);
	*/

	/* �Լ� �����ε�
	MyFunc();
	MyFunc('a');
	MyFunc(2,1);
	*/
	/*
	char name[100];
	char lang[200];

	cout << "�̸��� �Է����ּ��� :  ";
	cin >> name;

	cout << "�����ϴ� ��� �Է� :  ";
	cin >> lang;

	cout << name << lang << endl;
	*/

	/*
	int val;

	cout << "1��° ���� �Է� :  ";
	cin >> val;
	
	int val2;

	cout << "2��° ���� �Է� :  ";
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
	cout << "BestCom�� �Լ�." << endl;
}

void ProgComImpl::SimpleFunc(void)
{
	cout << "ProgCom�� �Լ�." << endl;
}

int adder(int num1, int num2)
{
	return num1 + num2;
}