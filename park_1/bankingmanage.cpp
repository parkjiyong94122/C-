#include "bankFunc.h"

int main(void)
{
	int num, acc_num, money;
	infor* accounts[MAX_ACCOUNT];
	infor* sel_account;
	int i=0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			if (i < MAX_ACCOUNT)
			{
				accounts[i] = create_account();
				i++;
			}
			else
				cout << "�� �̻� ���»����� �Ұ����մϴ�." << endl;
		}
		else if (num == 2)
		{
			cout << "[�Ա�]"<<endl;
			cout << "���� ID :";
			cin >> acc_num;
			cout << "�Աݾ�:";
			cin >> money;
			
			sel_account = compare(accounts, acc_num, i);

			if (sel_account == 0)
			{
				cout << "�ùٸ� ID �� �Է����ּ��� ";
			}
			else
			{
				Deposit(sel_account, money);
			}
		}
		else if (num == 3)
		{
			cout << "[���]" << endl;
			cout << "���� ID :";
			cin >> acc_num;
			cout << "��ݾ�:";
			cin >> money;
			sel_account = compare(accounts, acc_num, i);

			if (sel_account == 0)
			{
				cout << "�ùٸ� ���̵� �Է����ּ��� " << endl;
			}
			else
			{
				if (Withdraw(sel_account, money) == 0)
					cout << "�ݾ��� �����մϴ�." << endl;
			}
		}
		else if (num == 4)
		{
			for (int j = 0; j < i; j++)
			{
				Call_Account(accounts[j]);
			}
		}
		else if (num == 5)
		{
			Delete_account(accounts, i);
			break;
		}
		else
			cout << "�ùٸ� ���ڸ� �Է��ϼ��� " << endl;
	}
	return 0;
}