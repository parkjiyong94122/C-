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