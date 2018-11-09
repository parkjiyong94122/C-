#include"car.h"

using namespace std;

// �ڵ��� ���α׷�(������, ���ᷮ, ����ӵ�)

// ��� ����ü�� ���� �������� ����
namespace CAR_CONST
{
	const int ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 20, ACC_STEP = 10,BRK_STEP = 10;
	/*
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 20,
		ACC_STEP = 10,
		BRK_STEP = 10,
	};
	*/
}
/*
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 20
#define ACC_STEP 10
#define BRK_STEP 10
*/

/*
	car ����ü�� class�� ���� �� ����,
	- ĸ��ȭ (��������, ��������)
	- ���������� ���� ��������������
		public ��𼭵� ���ٰ���
		private Ŭ���� �������� ���ٰ���
		protected ��Ӱ��� ������ ���ٰ���
	- ��������
		�����ڰ� �м��� �����ϱ� ����.
		
*/

//class ĸ��ȭ(��������, ����) ��� �߻�ȭ ��
class Car
{

private:	
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(const char* id ,int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};
void Car::InitMembers(const char* id, int fuel)
{
	strcpy(gamerID, id);
	fuelGauge = fuel;
	curSpeed = 0;
}
void Car::ShowCarState()
{
	cout << "������ :" << gamerID << endl;
	cout << "���ᷮ :" << fuelGauge << endl;
	cout << "��  �� :" << curSpeed << endl;
}
void Car::Accel()
{
	//���ᷮ üũ
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;
	//�ְ� �ӵ� üũ
	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if (curSpeed - CAR_CONST::BRK_STEP < 0)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

void SwapByRef(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int & RefRetFuncOne(int &ref)
{
	ref++;
	return ref;
}

int main(void)
{
	//car ����ü ����� ���� �ʱ�ȭ,

	Car run77;
	run77.InitMembers("run77", 100);
	run77.Accel();
	run77.Accel();
	run77.ShowCarState();
	run77.Break();
	run77.ShowCarState();

	Car run88;
	run88.InitMembers("run88", 100);
	run88.Accel();
	run88.Break();
	run88.ShowCarState();

	//��ȯ���� �������� ���,
	/*
	int num = 1;

	int &num2 = RefRetFuncOne(num);
	// int &num2 = num;
	num++;
	num2++;
	cout << "num : " << num << endl;
	cout << "num2 : " << num2 << endl;
	*/

	//�����ڸ� �̿��� call by reference
	/*
	int val2 = 10, val3 = 20;

	SwapByRef(val2, val3);

	cout << "Val2 :" << val2 << endl;
	cout << "Val3 :" << val3 << endl;
	*/
	
	//call by value  ,call by reference
	/*
	call by value 
	���� ���ڷ� �����ϴ� �Լ� ȣ����
	call by reference
	�ּ� ���� ���ڷ� �����ϴ� �Լ� ȣ����
	*/
	//������ ������ ������� �� ������
	/*
	int num = 12;
	int *ptr = &num;
	int **dptr = &ptr;

	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;
	*/
	//�迭��Ҹ� ������� �� ������
	/*
	int arr[3] = { 1,2,3 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;
	*/

	// �Ϲ� ������ ������� �� ������
	/*
	//������ ���� ������ ����. �����ڸ� ������� �����ڸ� ���� �� �ִ�.
	int num1 = 1020; // ���� : �Ҵ�� �޸��� �̸�
	int &num2 = num1; //& = ���۷���(������) num1�� num2�� ����.
	int &num3 = num2;
	int &num4 = num3;

	//������ ���� �ȵǴ� �͵�
	//int &ref = 20;
	//int &ref;
	//int &ref = NULL;

	num2 = 3047;

	cout <<"VAL :" << num1 << endl;
	cout <<"REF 1 :" << num2 << endl;
	cout << "REF 2 :" << num3 << endl;
	cout << "REF 3 :" << num4 << endl;

	cout << "VAL :" << &num1 << endl;
	cout << "REF 1 :" << &num2 << endl;
	cout << "REF 2 :" << &num3 << endl;
	cout << "REF 3 :" << &num4 << endl;
	*/
	return 0;
}
