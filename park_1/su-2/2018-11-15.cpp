#include <iostream>

using namespace std;

/*�⺻ ���� ������*/
/*
class SoSimple
{
private:
	int num;
	int num2;
public:
	SoSimple(int n, int n2) : num2(n2), num(n)
	{}

	//���� ������(copy constructor)
	explicit SoSimple(SoSimple &copy) : num(copy.num), num2(copy.num2) // explicit ����  sim2 = sim1 �Ұ���
	{
		cout << "called Copy constructor " << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
		cout << num2 << endl;
	}
};
*/

int main(void)
{
	//���� ����(shallow copy), ���� ����(deep copy)

/*
	SoSimple simple1(20,40);

	//���� ������
	//SoSimple simple2 = simple1;
	SoSimple simple2(simple1);

	simple2.ShowSimpleData();
	*/

	return 0;
}