#include <iostream>

using namespace std;

/*기본 복사 생성자*/
/*
class SoSimple
{
private:
	int num;
	int num2;
public:
	SoSimple(int n, int n2) : num2(n2), num(n)
	{}

	//복사 생성자(copy constructor)
	explicit SoSimple(SoSimple &copy) : num(copy.num), num2(copy.num2) // explicit 사용시  sim2 = sim1 불가능
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
	//얕은 복사(shallow copy), 깊은 복사(deep copy)

/*
	SoSimple simple1(20,40);

	//복사 생성자
	//SoSimple simple2 = simple1;
	SoSimple simple2(simple1);

	simple2.ShowSimpleData();
	*/

	return 0;
}