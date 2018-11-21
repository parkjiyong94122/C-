#include<iostream>
#include<cstring>

using namespace std;

//예외 던지기
void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
			throw 0;
		cout << "몫 : " << num1 / num2 << endl;
		cout << "나머지 : " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw;
	}
}

class Point
{
private:
	int xpos, ypos;
	//복사 생성자
	//Point(const Point &ref){}
	//기본 대입 연산자 오버로딩
	//동일한 객체가 시스템 내에서 존재하지 않게 하기 위해
	//Point & operator=(const Point &ref);
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	void ShowData() const
	{
		cout << "X좌표 : " << xpos << " , " << "Y좌표 : " << ypos << endl;
	}
};

class BoundCheckPointArray
{
private:
	Point * arr;
	int arrlen;
	//복사 생성자
	//BoundCheckPointArray(const BoundCheckPointArray &arr){}
	//default 대입 연산자 오버로딩
	//BoundCheckPointArray & operator=(const BoundCheckPointArray& arr){}
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new Point[arrlen];
	}
	Point & operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "배열의 범위를 벗어났습니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
	~BoundCheckPointArray()
	{
		delete[] arr;
	}
};

int main(void)
{
	//예외 던지기
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)
	{
		cout << "second catch" << endl;
	}

	//객체 저장을 위한 배열 클래스 정의

	//BoundCheckPointArray arr(3);

	//default 대입연산자 호출
	/*
	arr[0] = Point(3, 4);	
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	arr[0].ShowData();
	arr[1].ShowData();
	arr[2].ShowData();
	*/
	//배열 복사
	/*
	BoundCheckPointArray cpy(3);
	cpy = arr;
	*/

	return 0;
}