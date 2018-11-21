#include"bank.h"

account::account(int num =0 , int mon = 0, char* nam =NULL)
	{
		number = num;
		money = mon;
		int len = strlen(nam) + 1;
		name = new char[len];
		strcpy(name, nam);
	}
account::account(account &copy) : number(copy.number), money(copy.money)
	{
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
	}
void account::CallAccount()const
	{
		cout << "����ID  :" << number << endl << "�̸� :" << name << endl << "�Աݾ� :" << money << endl;
	}
int account::compare(int num)
	{
		if (number == num)
			return 1;
		else
			return 0;
	}
void account::Deposit(int mon)  throw (DepositException)
{
	if(mon<0)
	{
		DepositException expn(mon);
		throw expn;
	}
	money += mon;
}
void account::Withdraw(int mon) throw (WithdrawException)
{
	if (money < mon)
	{
		WithdrawException expn(mon);
		throw expn;
	}
		money -= mon;
}
account::~account()
	{
		cout << "������ " << endl;
		delete name;
	}

NormalAccount::NormalAccount(int num, int mon, char* nam, double rate) : account(num, mon, nam), interestRate(rate*0.01)
	{}
void NormalAccount::Deposit(int mon)
	{
		account::Deposit(mon);
		account::Deposit((int)(mon*interestRate));
	}
void NormalAccount::CallAccount() const
	{
		account::CallAccount();
		cout << "������ : " << interestRate * 100 << endl;
	}

HighCreditAccount::HighCreditAccount(int num, int mon, char* nam, double rate, char special) : account(num, mon, nam), specialRate(special), interestRate(rate*0.01)
	{
		if (special == 'A')
			interestRate += 0.7;
		else if (special == 'B')
			interestRate += 0.4;
		else if (special == 'C')
			interestRate += 0.2;
	}
void HighCreditAccount::Deposit(int mon)
	{
		account::Deposit(mon);
		account::Deposit((int)(mon*interestRate));
	}
void HighCreditAccount::CallAccount() const
	{
		account::CallAccount();
		cout << "������ : " << interestRate * 100 << endl;
		cout << "����� : " << specialRate << endl;
	}

BoundCheckPointArray::BoundCheckPointArray(int len) : acclen(len)
{
	acc = new account*[len];
}
account* BoundCheckPointArray::operator[](int idx)
{
	if (idx < 0 || idx > acclen)
	{
		cout << "�� �̻� ���¸� ������ �� �����ϴ�." << endl;
		exit(1);
	}
	return acc[idx];
}
BoundCheckPointArray::~BoundCheckPointArray()
{
	delete[] acc;
}

ControlBank::ControlBank() :account_num(0), accounts(MAX_ACCOUNT)
{}
int ControlBank::AccountCompare(int num)
	{
		for (int cur = 0; cur < account_num; cur++)
		{
			if (accounts[cur]->compare(num) == 1)
				return cur;
		}
		return -1;
	}
void ControlBank::CreateAccounts(account* account)
{
	int sel_count = AccountCompare(account_num);
	if (sel_count != -1)
	{
		cout << "���� ID ���� ������ �Ұ����մϴ�." << endl;
	}
	else
	{
		//accounts[account_num] = account;
		accounts[account_num] = account;
		account_num++;
	}
		//���� id ����
}
	//�Ա�
int ControlBank::DepositAccounts(int num, int money)
	{
		int sel_count = AccountCompare(num);
		if (sel_count == -1)
		{
			cout << "�ùٸ� ID �� �Է����ּ��� " << endl;
		}
		else
		{
			try
			{
				accounts[sel_count]->Deposit(money);
			}
			catch (AccountException & expn)
			{
				expn.ShowResult();
				return 1;
			}
			return 0;
		}
	}
	//���
int ControlBank::WithdrawAccounts(int num, int money) 
	{
		int sel_count = AccountCompare(num);
		if (sel_count == -1)
		{
			cout << "�ùٸ� ID �� �Է����ּ��� " << endl;
		}
		else
		{
			try
			{
				accounts[sel_count]->Withdraw(money);
			}
			catch (AccountException & expn)
			{
				expn.ShowResult();
				return 1;
			}
			return 0;
		}
	}
	//Ȯ��
void ControlBank::ShowAllAccounts()
	{
		for (int cur = 0; cur < account_num; cur++)
		{
			accounts[cur]->CallAccount();
		}
	}
	//����
void ControlBank::DeleteAccounts()
	{
	/*
		for (int cur = 0; cur < account_num; cur++)
		{
			delete accounts[cur];
		}
	*/
	}



DepositException::DepositException(int money) : myMoney(money)
{}
void DepositException::ShowResult()
	{
		cout << "�Ա� ���� : " << myMoney << "�� �Ա��� �� �����ϴ�." << endl;
	}



WithdrawException::WithdrawException(int money) : myMoney(money)
	{}
void WithdrawException::ShowResult()
	{
		cout << "��� ���� : " << myMoney << "�� ����� �� �����ϴ�." << endl;
	}



void call_menu()
	{
		cout << "---------Menu---------" << endl;
		cout << "1. ���� ���� " << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl << endl;

		cout << "���� : ";
	}