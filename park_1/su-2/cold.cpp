#include<iostream>
using namespace std;

class ColdMedicine
{
	//���� ����, ġ�ᰡ���� ����, 

	//�ʱ�ȭ, �� ���
};

//�๰ ĸ��
class SinivelCap
{
public:
	void Take()
	{
		cout << "�๰�� �ܽ��ϴ�." << endl;
	}
};
//��ä�� ĸ��
class SneezeCap
{
public:
	void Take()
	{
		cout << "��ä�Ⱑ �ܽ��ϴ�." << endl;
	}
};
//�ڸ��� ĸ��
class SnuffleCap
{
public:
	void Take()
	{
		cout << "�ڰ� �ո��ϴ�." << endl;
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
	//���� ����,ȯ�� Ư¡, ���� ����

	//�ʱ�ȭ ,���� ���,�� ó��, �� ����
public:
	//�๰�� ����
	void TakeSinivelCap(SinivelCap &cap)
	{
		cap.Take();
	}
	//��ä��� ����
	void TakeSneezeCap(SneezeCap &cap)
	{
		cap.Take();
	}
	//�ڸ����� ����
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