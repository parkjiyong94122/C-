#include"coldpatient.h"

using namespace std;

//�๰ ĸ��
void SinivelCap::Take()
{
	cout << "�๰�� �ܽ��ϴ�." << endl;
}

//��ä�� ĸ��
void  SneezeCap::Take()
{
	cout << "��ä�Ⱑ �ܽ��ϴ�." << endl;
}

//�ڸ��� ĸ��
void SnuffleCap::Take()
{		
	cout << "�ڰ� �ո��ϴ�." << endl;
}

void AllCap::Take()
{	
	sin.Take();
	sne.Take();
	snu.Take();
}

//�๰�� ����
void ColdPatient::TakeSinivelCap(SinivelCap &cap)
{
	cap.Take();
}

//��ä��� ����
void ColdPatient::TakeSneezeCap(SneezeCap &cap)
{
	cap.Take();
}

//�ڸ����� ����
void ColdPatient::TakeSnuffleCap(SnuffleCap &cap)
{
	cap.Take();
}

//���� ����
void ColdPatient::TakeCap(AllCap &cap)
{
	cap.Take();
}
