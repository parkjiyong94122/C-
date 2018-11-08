#include"bankFunc.h"

void call_menu()
{
	cout << "---------Menu---------" << endl;
	cout << "1. 계좌 개설 " << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;

	cout << "선택 ";
}
infor *create_account()
{
	infor* m;
	m = (infor*)malloc(sizeof(infor));
	cout << " 계좌 ID : ";
	cin >> m->number;
	cout << " 이름	  : ";
	cin >> m->name;
	cout << " 입금액  : ";
	cin >> m->money;

	return m;
}
void Call_Account(infor* account)
{
	cout << "계좌ID  :" << account->number << endl << "이름 :" << account->name << endl << "입금액 :" << account->money << endl;

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