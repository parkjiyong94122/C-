#include<iostream>

using namespace std;

//self_reference(자기참조의 이해)
class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체 생성" << endl;
	}
	SelfRef &Adder(int n)
	{
		num += n;

		return *this;
	}
	void ShowNumber()
	{
		cout << num << endl;
	}
};

//this pointer의 활용
/*
class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	void ShowTwoNumber()
	{
		cout << "num1 :" << num1 << endl;
		cout << "num2 :" << num2 << endl;
	}
};
*/

//this pointer의 이해
/*
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num = " << num << endl;
		cout << "address = " << this << endl;
	}
	void ShowSoSimpleData()
	{
		cout << num << endl;
	}
	SoSimple * GetThisPointer()
	{
		return this;
	}
};

*/
int main(void)
{
	//self_reference(자기참조의 이해)
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowNumber();
	ref.ShowNumber();

	//this pointer의 활용
	/*
	TwoNumber tn1(10,20);
	tn1.ShowTwoNumber();
	*/
	//this pointer의 이해
	/*
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << " . ";
	ptr1->ShowSoSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << " . ";
	ptr2->ShowSoSimpleData();
	*/
	return 0;
}