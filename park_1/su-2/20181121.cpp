#include<iostream>
#include<cstring>

using namespace std;

//���� ������
void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
			throw 0;
		cout << "�� : " << num1 / num2 << endl;
		cout << "������ : " << num1 % num2 << endl;
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
	//���� ������
	//Point(const Point &ref){}
	//�⺻ ���� ������ �����ε�
	//������ ��ü�� �ý��� ������ �������� �ʰ� �ϱ� ����
	//Point & operator=(const Point &ref);
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	void ShowData() const
	{
		cout << "X��ǥ : " << xpos << " , " << "Y��ǥ : " << ypos << endl;
	}
};

class BoundCheckPointArray
{
private:
	Point * arr;
	int arrlen;
	//���� ������
	//BoundCheckPointArray(const BoundCheckPointArray &arr){}
	//default ���� ������ �����ε�
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
			cout << "�迭�� ������ ������ϴ�." << endl;
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
	//���� ������
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)
	{
		cout << "second catch" << endl;
	}

	//��ü ������ ���� �迭 Ŭ���� ����

	//BoundCheckPointArray arr(3);

	//default ���Կ����� ȣ��
	/*
	arr[0] = Point(3, 4);	
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	arr[0].ShowData();
	arr[1].ShowData();
	arr[2].ShowData();
	*/
	//�迭 ����
	/*
	BoundCheckPointArray cpy(3);
	cpy = arr;
	*/

	return 0;
}