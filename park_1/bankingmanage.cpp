#include "bankFunc.h"

int main(void)
{
	int num, acc_num, money;
	infor* accounts[MAX_ACCOUNT];
	infor* sel_account;
	int account_num=0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			if (account_num < MAX_ACCOUNT)
			{
				accounts[account_num] = create_account();
				account_num++;
			}
			else
				cout << "더 이상 계좌생성이 불가능합니다." << endl;
		}
		else if (num == 2)
		{
			cout << "[입금]"<<endl;
			cout << "계좌 ID :";
			cin >> acc_num;
			cout << "입금액:";
			cin >> money;
			
			sel_account = compare(accounts, acc_num, i);

			if (sel_account == 0)
			{
				cout << "올바른 ID 를 입력해주세요 ";
			}
			else
			{
				Deposit(sel_account, money);
			}
		}
		else if (num == 3)
		{
			cout << "[출금]" << endl;
			cout << "계좌 ID :";
			cin >> acc_num;
			cout << "출금액:";
			cin >> money;
			sel_account = compare(accounts, acc_num, account_num);

			if (sel_account == 0)
			{
				cout << "올바른 아이디를 입력해주세요 " << endl;
			}
			else
			{
				if (Withdraw(sel_account, money) == 0)
					cout << "금액이 부족합니다." << endl;
			}
		}
		else if (num == 4)
		{
			for (int j = 0; j < account_num; j++)
			{
				Call_Account(accounts[j]);
			}
		}
		else if (num == 5)
		{
			Delete_account(accounts, account_num);
			break;
		}
		else
			cout << "올바른 숫자를 입력하세요 " << endl;
	}
	return 0;
}