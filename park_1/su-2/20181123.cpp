#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	int len;
	char* str;
public:
	String();						//�Ű����� ���� ������
	String(const char* s);			//�Ű����� �ִ� ������
	String(const String& s);		//���������
	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	String& operator==(const String& s);
};

String::String()
{
	len = 0;
	str = NULL;
}
String::String(const char* s)
{

}

int main(void)
{
	/*
	string str1 = "i like string class.";
	string str2 = "me too.";
	string str3 = str1 + str2;

	if (str1 == str3)
		cout << "���� ���ڿ�" << endl;
	else
		cout << "�ٸ� ���ڿ�" << endl;

	string str4;
	cout << "���ڿ� �Է� : ";
	cin >> str4;
	cout << "�Է��� ���ڿ� :" << str4 << endl;
	*/

	return 0;
}