
#include"coldpatient.h"

using namespace std;


//콧물 캡슐
void SinivelCap::Take()
{
	cout << "콧물이 멎습니다." << endl;
}

//재채기 캡슐

void  SneezeCap::Take()
{
	cout << "재채기가 멎습니다." << endl;
}

//코막힘 캡슐

void SnuffleCap::Take()
{		
	cout << "코가 뚫립니다." << endl;
}


void AllCap::Take()
{	
	sin.Take();
	sne.Take();
	snu.Take();
}



	//감기 증상,환자 특징, 감기 세기

	//초기화 ,상태 출력,약 처방, 약 섭취

	//콧물약 복용
void ColdPatient::TakeSinivelCap(SinivelCap &cap)
{
	cap.Take();
}
//재채기약 복용
void ColdPatient::TakeSneezeCap(SneezeCap &cap)
{
	cap.Take();
}
//코막힘약 복용
void ColdPatient::TakeSnuffleCap(SnuffleCap &cap)
{
	cap.Take();
}
void ColdPatient::TakeCap(AllCap &cap)
{
	cap.Take();
}
