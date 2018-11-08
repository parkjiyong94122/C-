#include <iostream>


using namespace std;

int main(void)
{
	char name[100];
	char lang[200];

	cout << "이름을 입력해주세요 :  ";
	cin >> name;

	cout << "좋아하는 언어 입력 :  ";
	cin >> lang;

	cout << name << lang << endl;


	/*&
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