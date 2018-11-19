#include<iostream>
#include<cstring>

using namespace std;

// mutable 쓸일이 거의 없음.
class SoSimple
{
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{}
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1; // const 멤버 변수 변경 가능.
	}
};

//static 함수 (클래스 함수)
/*
class SoSimple
{
private:
	int num1;
	static int num2;
public:
	SoSimple(int n) : num1(n)
	{}
	static void Adder(int n)
	{
		num2 += n; //클래스 함수내에서는 클래스 변수만 변경가능 , 같은 영역만 변경가능.
	}
};
int SoSimple::num2;
*/
//const static 변수 (클래스 변수)
class CountryArea
{
public:
	const static int RUSSIA = 8976;
	const static int SOUTH_KOREA = 7877;
};
//static 변수 (클래스 변수)
/*
//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple
{
private:
	static int simObjCnt; //생성시마다 초기화 하지 않기위해 초기화 안됨.
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체"<<endl;
	}
};
int SoSimple::simObjCnt;

class SoComplx
{
private:
	static int cmxObjCnt;
public:
	SoComplx()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplx 객체" << endl;
	}
};
int SoComplx::cmxObjCnt;
*/
//정적 지역 변수
/*
void Counter()
{
	static int cnt;
	cnt++;
	cout << "Current cnt : " << cnt << endl;

}
*/
/*friend 선언 class
class Girl;
class boy
{
private:
	int height;
	friend class Girl;
public:
	boy(int len) : height(len)
	{}
	void ShowYourFriendInfo(Girl &frn);
};
class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(boy &frn);
	friend class  boy;
};
void Girl::ShowYourFriendInfo(boy &frn)
{
	cout << "his height : " << frn.height << endl;
}
void boy::ShowYourFriendInfo(Girl &frn)
{
	cout << "Her phone number : " << frn.phNum << endl;
}
*/
//friend 선언 - 함수 인 경우
/*
class point;

class pointOP
{
private:
	int opCnt;
public:
	pointOP() : opCnt(0)
	{}
	point PointAdd(const point&, const point&);
	point PointSub(const point&, const point&);
	~pointOP()
	{
		cout << "operation times : " << opCnt << endl;
	}
};
class point
{
private:
	int x;
	int y;
public:
	point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{}
	friend point pointOP::PointAdd(const point&, const point&);
	friend point pointOP::PointSub(const point&, const point&);
	friend void ShowPointPos(const point&);
};

point pointOP::PointAdd(const point& pnt1, const point& pnt2)
{
	opCnt++;
	return point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}
point pointOP::PointSub(const point& pnt1, const point& pnt2)
{
	opCnt++;
	return point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}
void ShowPointPos(const point& pos)
{
	cout << "x: " << pos.x << "." << "y : " << pos.y << endl;
}
/*

/*const 함수 오버로딩
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple & AddNum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "simpleFunc :  " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const simpleFunc :  " << num << endl;
	}
};
*/
/*const 객체
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple & AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num : " << num << endl;
	}
};
*/
int main(void)
{
	//C언어 정적 지역 변수
	/*
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	*/
	//static 변수 (클래스 변수)
	/*
	SoSimple sim1;
	SoSimple sim2;

	SoComplx cmx1;
	SoComplx cmx2;
	SoComplx cmx3;
	*/
	//const static 변수 (클래스 변수)
	cout << "러시아 면적 : " << CountryArea::RUSSIA << endl;
	cout << "한국	면적 : " << CountryArea::SOUTH_KOREA << endl;

	//static 함수 (클래스 함수)
	/*	
		- 선언된 클래스의 모든 객체가 공유
		- public로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능.
		- 객체의 멤버로 존재하는 것이 아님.
	*/

	// mutable 키워드
	/*	- const 함수 내에서 멤버변수 값의 변경을 에외적으로 허용.
	*/
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();

	//friend 선언 - class 인 경우
	/*	- friend 선언은 객체지향의 캡술화에서 정보은닉을 위배하는 문법임.
		- 따라서 friend 선언은 필요한 상황에서만 사용해야함.
		- 연산자 오버로딩에서 전역 함수를 선언시 사용.

	boy b(180);
	Girl girl("010-1111-1111");

	b.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(b);
	*/
	//friend 선언 - 함수 인 경우
	/*
	point pos1(1, 2);
	point pos2(2, 4);
	pointOP op;
	
	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	*/

	// const 함수 오버로딩
	/*	함수 오버로딩 조건에서 const도 포함됨.
	SoSimple obj1(7);
	const SoSimple obj2(10);

	obj1.SimpleFunc();
	obj2.SimpleFunc();
	*/
	// const 객체
	/*	const 객체는 const 함수만 호출 가능.
		객체의 멤버변수 변경을 허용하지 않음.

	
	SoSimple generalObj(10);
	generalObj.AddNum(10);
	generalObj.ShowData();

	const SoSimple constObj(100); 
	constObj.ShowData();
	//constObj.AddNum(10);
	*/
	return 0;
}