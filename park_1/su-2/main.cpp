#include<iostream>
#include<cstring>

using namespace std;

//������ �����ε�
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}
	void ShowPoistion() const
	{
		cout << '[' << xpos <<". " <<ypos<< ']' << endl;
	}

	//����Լ��� ���� ������ �����ε�	*���׿���
	/*
	Point operator+(const Point &ref) const
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	*/
	/*
	Point & operator--(int)		//���� ���� ����
	{
		xpos--;
		ypos--;
		return *this;
	}
	*/
	Point operator--(int)
	{
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;
	}
	//�����Լ��� ���� ������ �����ε�
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}

	friend Point operator+(const Point &pos1,const Point &pos2);	//���� ����
	friend Point & operator++(Point &pos);						//���� ����
	friend Point operator++(Point &pos,int);					//���� ����
};
/*���� ���� ����
Point & operator++(Point &pos)
{
	pos.xpos++;
	pos.ypos++;
	return pos;
}
*/
Point operator++(Point &pos, int)
{
	const Point retobj(pos.xpos, pos.ypos);
	pos.xpos += 1;
	pos.ypos += 1;
	return retobj;
}

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

// mutable ������ ���� ����.
/*
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
		num2 = num1; // const ��� ���� ���� ����.
	}
};
*/

//static �Լ� (Ŭ���� �Լ�)
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
		num2 += n; //Ŭ���� �Լ��������� Ŭ���� ������ ���氡�� , ���� ������ ���氡��.
	}
};
int SoSimple::num2;
*/

//const static ���� (Ŭ���� ����)
class CountryArea
{
public:
	const static int RUSSIA = 8976;
	const static int SOUTH_KOREA = 7877;
};

//static ���� (Ŭ���� ����)
/*
//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple
{
private:
	static int simObjCnt; //�����ø��� �ʱ�ȭ ���� �ʱ����� �ʱ�ȭ �ȵ�.
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü"<<endl;
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
		cout << cmxObjCnt << "��° SoComplx ��ü" << endl;
	}
};
int SoComplx::cmxObjCnt;
*/

//���� ���� ����
/*
void Counter()
{
	static int cnt;
	cnt++;
	cout << "Current cnt : " << cnt << endl;

}
*/

/*friend ���� class
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

//friend ���� - �Լ� �� ���
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

/*const �Լ� �����ε�
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

/*const ��ü
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
	// �ڷ����� �ٸ� ����� ������ �����ε�
	/**/
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPoistion();

	//������ �����ε�
	/*	- �����ڰ� �����ε� �Ǹ�, �ǿ������� ������ ���� ������ ����� 
		�޶����� ���� ����.
	*/
	// ���� ������
	/*
	Point pos1(3, 4);
	Point pos2(10, 10);
	
	//������ �����ε�
	//- ����Լ��� ���� �����ε�
	//- �����Լ��� ���� �����ε�
	//Point pos3 = pos1 + pos2;
	//Point pos3 = pos1.operator+(pos2);
	//�����Ϸ��� pos1+pos2 �� pos1.operator+(pos2)�� �ؼ��ؼ� ������.
	
	Point pos3 = pos1 + pos2;

	pos1.ShowPoistion();
	pos2.ShowPoistion();
	pos3.ShowPoistion();
	*/

	// ���� ������ �����ε�
	/*
	Point pos(1, 2);
	Point cpy;
	//num++ ���� ��� �� num�� ����
	//++num ���� ��� �� num �� ����
	*/
	//(���� ������)
	/*
	//++pos;
	//pos.operator++();		//����Լ��� ���
	//operator++(pos);		//�����Լ��� ���
	pos.ShowPoistion();
	--pos;
	//pos.operator--();		//����Լ��� ���
	//operator--(pos);		//�����Լ��� ���
	pos.ShowPoistion();

	++(++pos);
	pos.ShowPoistion();
	--(--pos);
	pos.ShowPoistion();
	*/

	//���� ������
	/*
	//pos.operator--();		����
	//pos.operator++();		����
	//pos.operator--(int);  ����
	//pos.operator++(int);  ����
	/*
	
	cpy = pos--;
	//pos.operator--();		//����Լ��� ���
	//operator--(pos);		//�����Լ��� ���
	pos.ShowPoistion();
	cpy.ShowPoistion();

	cpy = (pos++);
	pos.ShowPoistion();
	cpy.ShowPoistion();
	*/

	//C��� ���� ���� ����
	/*
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	*/
	//static ���� (Ŭ���� ����)
	/*
	SoSimple sim1;
	SoSimple sim2;

	SoComplx cmx1;
	SoComplx cmx2;
	SoComplx cmx3;
	*/
	//const static ���� (Ŭ���� ����)
	/*
	cout << "���þ� ���� : " << CountryArea::RUSSIA << endl;
	cout << "�ѱ�	���� : " << CountryArea::SOUTH_KOREA << endl;
	*/
	//static �Լ� (Ŭ���� �Լ�)
	/*	
		- ����� Ŭ������ ��� ��ü�� ����
		- public�� ������ �Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ���� ����.
		- ��ü�� ����� �����ϴ� ���� �ƴ�.
	*/

	// mutable Ű����
	/*	- const �Լ� ������ ������� ���� ������ ���������� ���.
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	*/
	//friend ���� - class �� ���
	/*	- friend ������ ��ü������ ĸ��ȭ���� ���������� �����ϴ� ������.
		- ���� friend ������ �ʿ��� ��Ȳ������ ����ؾ���.
		- ������ �����ε����� ���� �Լ��� ����� ���.

	boy b(180);
	Girl girl("010-1111-1111");

	b.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(b);
	*/
	//friend ���� - �Լ� �� ���
	/*
	point pos1(1, 2);
	point pos2(2, 4);
	pointOP op;
	
	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	*/

	// const �Լ� �����ε�
	/*	�Լ� �����ε� ���ǿ��� const�� ���Ե�.
	SoSimple obj1(7);
	const SoSimple obj2(10);

	obj1.SimpleFunc();
	obj2.SimpleFunc();
	*/
	// const ��ü
	/*	const ��ü�� const �Լ��� ȣ�� ����.
		��ü�� ������� ������ ������� ����.

	
	SoSimple generalObj(10);
	generalObj.AddNum(10);
	generalObj.ShowData();

	const SoSimple constObj(100); 
	constObj.ShowData();
	//constObj.AddNum(10);
	*/

	return 0;
}