#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	int len;
	char* str;
public:
	String();						//매개변수 없는 생성자
	String(const char* s);			//매개변수 있는 생성자
	String(const String& s);		//복사생성자
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
		cout << "동일 문자열" << endl;
	else
		cout << "다른 문자열" << endl;

	string str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 :" << str4 << endl;
	*/

	return 0;
}