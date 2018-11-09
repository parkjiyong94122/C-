#include"car.h"

using namespace std;

// 자동차 프로그램(소유자, 연료량, 현재속도)

// 어느 구조체에 들어가는 가독성을 위해

/*
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 20
#define ACC_STEP 10
#define BRK_STEP 10
*/

/*
	car 구조체를 class로 변경 및 적용,
	- 캡슐화 (정보은닉, 법위설정)
	- 정보은닉을 위한 접근제어지시자
		public 어디서든 접근가능
		private 클래스 내에서만 접근가능
		protected 상속관계 내에서 접근가능
	- 범위설정
		개발자가 분석후 정의하기 나름.
		
*/

//class 캡슐화(정보은닉, 범위) 상속 추상화 다



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
	//car 구조체 사용을 위한 초기화,

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

	//반환형이 참조자인 경우,
	/*
	int num = 1;

	int &num2 = RefRetFuncOne(num);
	// int &num2 = num;
	num++;
	num2++;
	cout << "num : " << num << endl;
	cout << "num2 : " << num2 << endl;
	*/

	//참조자를 이용한 call by reference
	/*
	int val2 = 10, val3 = 20;

	SwapByRef(val2, val3);

	cout << "Val2 :" << val2 << endl;
	cout << "Val3 :" << val3 << endl;
	*/
	
	//call by value  ,call by reference
	/*
	call by value 
	값을 인자로 전달하는 함수 호출방식
	call by reference
	주소 값을 인자로 전달하는 함수 호출방식
	*/
	//포인터 변수를 대상으로 한 참조자
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
	//배열요소를 대상으로 한 참조자
	/*
	int arr[3] = { 1,2,3 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;
	*/

	// 일반 변수를 대상으로 한 참조자
	/*
	//참조자 수는 제한이 없다. 참조자를 대상으로 참조자를 만들 수 있다.
	int num1 = 1020; // 변수 : 할당된 메모리의 이름
	int &num2 = num1; //& = 레퍼런스(참조자) num1을 num2가 참조.
	int &num3 = num2;
	int &num4 = num3;

	//참조자 선언 안되는 것들
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
