#include<iostream>
using namespace std;

class ColdMedicine
{
	//약의 세기, 치료가능한 증상, 

	//초기화, 약 출력
};

//콧물 캡슐
class SinivelCap
{
public:
	void Take()
	{
		cout << "콧물이 멎습니다." << endl;
	}
};
//재채기 캡슐
class SneezeCap
{
public:
	void Take()
	{
		cout << "재채기가 멎습니다." << endl;
	}
};
//코막힘 캡슐
class SnuffleCap
{
public:
	void Take()
	{
		cout << "코가 뚫립니다." << endl;
	}
};
class AllCap
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;
public:
	void take()
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}

};

class ColdPatient
{
	//감기 증상,환자 특징, 감기 세기

	//초기화 ,상태 출력,약 처방, 약 섭취
public:
	//콧물약 복용
	void TakeSinivelCap(SinivelCap &cap)
	{
		cap.Take();
	}
	//재채기약 복용
	void TakeSneezeCap(SneezeCap &cap)
	{
		cap.Take();
	}
	//코막힘약 복용
	void TakeSnuffleCap(SnuffleCap &cap)
	{
		cap.Take();
	}
	void TakeCap(AllCap &cap)
	{
		cap.Take();
	}
};


int main(void)
{
	ColdPatient patient;
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;
	AllCap acap;

	//patient.TakeSinivelCap(scap);
	//patient.TakeSneezeCap(zcap);
	//patient.TakeSnuffleCap(ncap);

	patient.TakeCap(acap);

}