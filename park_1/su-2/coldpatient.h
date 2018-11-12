#include<iostream>
#pragma once
class ColdMedicine
{
	//약의 세기, 치료가능한 증상, 

	//초기화, 약 출력
};

//콧물 캡슐
class SinivelCap
{
public:
	void Take();
};
//재채기 캡슐
class SneezeCap
{
public:
	void Take();
};
//코막힘 캡슐
class SnuffleCap
{
public:
	void Take();
};
class AllCap
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;
public:
	void Take();
};

class ColdPatient
{
	//감기 증상,환자 특징, 감기 세기

	//초기화 ,상태 출력,약 처방, 약 섭취
public:
	//콧물약 복용
	void TakeSinivelCap(SinivelCap &cap);
	//재채기약 복용
	void TakeSneezeCap(SneezeCap &cap);
	//코막힘약 복용
	void TakeSnuffleCap(SnuffleCap &cap);
	void TakeCap(AllCap &cap);
};