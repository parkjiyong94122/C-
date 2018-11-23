#include <iostream>
#include <cstring>

using namespace std;
//string
/*
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
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	~String();
};

String::String()
{
	len = 0;
	str = NULL;
}
String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
String& String::operator=(const String& s)
{
	if(str != NULL)
		delete str;

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}
String String::operator+(const String& s)
{
	String newStr(strcat(str, s.str));

	return newStr;
}
String& String::operator+=(const String& s)
{
	len = len + s.len -1;
	char* newstr = new char[len];
	newstr = strcat(str, s.str);
	delete str;

	str = newstr;

	return *this;
}
bool String::operator==(const String& s)
{
	return strcmp(s.str, str) ? false : true;
}

// 
//입출력을 위해 iostream 헤더파일을 사용
//입력 : istream class
//출력 : ostream class
//

//출력을 위한 << 연산자 오버로딩
ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

//입력을 위한 >> 연산자 오버로딩
istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> s.str;
	s = String(str);

	return is;
}
String::~String()
{
	if (str != NULL)
		delete[]str;
}

int main(void)
{

	String str1 = "i like string class.";
	String str2 = "me too.";
	String str3 = str1 + str2;
	
	cout << str1 << endl;
	cout << str2 << endl;
	str1 += str2;
	cout << str1 << endl;
	cout << str3 << endl;


	if (str1 == str3)
		cout << "동일 문자열" << endl;
	else
		cout << "다른 문자열" << endl;

	String str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 :" << str4 << endl;


	return 0;
}*/

//	템플릿 template
/*	뜻 : 형판 -> 모형자
	-함수 템플릿, 클래스 템플릿
	다양한 자료형의 함수, 클래스를 만드는 도구.

	int Add(int num1, int num2)
	{
		return num1+num2;
	}

	기능 : 덧셈
	대상 자료형 : int 데이터

	template <typename T>
	template <class T>

	T Add(T num1, T num2)
	{
		return num1+ num2;
	}
*/
template <class T1, class T2>
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

template <typename T>
T Add(T num1, T num2)
{
	cout << "Template Add" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "Add" << endl;
	return num1 + num2;
}

//템플릿의 특수화 
template <typename T>
T Max(T a, T b )
{
	return a > b ? a : b;
}

template <>
char* Max(char* a, char* b)
{
	cout << "char* Max(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{

	//<int> : T를 int로 해서 만들어진 함수를 호출. => 템플릿 함수
	// 템플릿 함수 : 템플릿을 기반으로 컴파일러가 만들어 내는 유형의 함수.
	
	/*
	cout << Add(15, 20) << endl;
	cout << Add<int>(15, 20) << endl;
	cout << Add(15, 20) << endl;
	cout << Add<double>(1.5, 2.3) << endl;
	ShowData<char, int>(65);
	*/

	//템플릿의 특수화
	/*
	//기준이 명확한 경우
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 10.5) << endl;

	//기준이 애매한 경우
	// const char *
	cout << Max("Simple", "QQQQQQQQQQ") << endl;

	//char*
	char str1[] = "Simple";
	char str2[] = "QQQQQQQQQQQQQ";
	cout << Max(str1, str2) << endl;
	*/
	return 0;
}