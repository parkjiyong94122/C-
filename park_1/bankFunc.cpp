#include"bankFunc.h"



void call_menu()
{
	cout << "---------Menu---------" << endl;
	cout << "1. ���� ���� " << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;

	cout << "���� ";
}
void account::Call_Account()
{
	cout << "����ID  :" << << endl << "�̸� :" <<<< endl << "�Աݾ� :" << account->money << endl;

}
account()
{
	infor* m;
	m = (infor*)malloc(sizeof(infor));
	cout << " ���� ID : ";
	cin >> m->number;
	cout << " �̸�	  : ";
	cin >> m->name;
	cout << " �Աݾ�  : ";
	cin >> m->money;

	return m;
}


infor *compare(infor** account, int num, int count)
{
	for (int j = 0; j < count; j++)
	{
		if (account[j]->number == num)
			return account[j];

		else if(j == count - 1)
			return 0;
	}
}
void Deposit(infor* account, int money)
{
	account->money += money;
}
int Withdraw(infor* account, int money)
{
	if (account->money < money)
		return 0;
	else
		account->money -= money;
}
void Delete_account(infor** account, int count)
{
	for (int j = 0; j < count; j++)
	{
		free(account[j]);
	}
}