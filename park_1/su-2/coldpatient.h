#include<iostream>
#pragma once
class ColdMedicine
{
	//���� ����, ġ�ᰡ���� ����, 

	//�ʱ�ȭ, �� ���
};

//�๰ ĸ��
class SinivelCap
{
public:
	void Take();
};
//��ä�� ĸ��
class SneezeCap
{
public:
	void Take();
};
//�ڸ��� ĸ��
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
	//���� ����,ȯ�� Ư¡, ���� ����

	//�ʱ�ȭ ,���� ���,�� ó��, �� ����
public:
	//�๰�� ����
	void TakeSinivelCap(SinivelCap &cap);
	//��ä��� ����
	void TakeSneezeCap(SneezeCap &cap);
	//�ڸ����� ����
	void TakeSnuffleCap(SnuffleCap &cap);
	void TakeCap(AllCap &cap);
};