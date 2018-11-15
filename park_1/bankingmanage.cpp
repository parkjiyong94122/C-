#define MAX_ACCOUNT 100
#include <iostream>
#include <cstring>

using namespace std;
void call_menu();


class account
{
private:
	int money;
	int number;
	char* name;

public:
	account(int num, int mon, char* nam)
	{
		number = num;
		money = mon;
		int len = strlen(nam) + 1;
		name = new char[len];
		strcpy(name, nam);
	}
	account(account &copy) : number(copy.number), money(copy.money)
	{
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
	}
	virtual void CallAccount()const
	{
		cout << "����ID  :" << number << endl << "�̸� :" << name << endl << "�Աݾ� :" << money << endl;
	}
	int compare(int num)
	{
		if (number == num)
			return 1;
		else 
			return 0;
	}
	virtual void Deposit(int mon)
	{
		money += mon;
	}
	void Withdraw(int mon)
	{
		if (money < mon)
			cout << "�ܾ��� �����մϴ�." << endl;
		else
			money -= mon;
	}
	~account()
	{
		cout << "������ " << endl;
		delete name;
	}
};
class NormalAccount : public account
{
private:
	double interestRate;
public:
	NormalAccount(int num, int mon, char* nam, double rate) : account(num,mon,nam),interestRate(rate)
	{}
	void Deposit(int mon)
	{
		account::Deposit(mon);
		account::Deposit((int)(mon*interestRate));
	}
	void CallNormalAccount() const
	{
		account::CallAccount();
		cout << "������ : " << interestRate << endl;
	}
};

class HighCreditAccount : public account
{
private:
	double interestRate;
	char specialRate;
public:
	HighCreditAccount(int num, int mon, char* nam, double rate , char special) : account(num, mon, nam), specialRate(special), interestRate(rate)
	{
		if (special == 'A')
			interestRate += 0.7;
		else if(special == 'B')
			interestRate += 0.4;
		else if (special == 'C')
			interestRate += 0.2;
	}
	void Deposit(int mon)
	{
		account::Deposit(mon);
		account::Deposit((int)(mon*interestRate));
	}
	void CallAccount() const
	{
		account::CallAccount();
		cout << "������ : " << interestRate << endl;
		cout << "����� : " << specialRate << endl;
	}
};
class ControlBank
{
private:
	account *accounts[MAX_ACCOUNT];
	int account_num;
public:
	ControlBank() :account_num(0)
	{}
	int AccountCompare(int num)
	{
		for (int cur = 0; cur > account_num; cur++)
		{
			if (accounts[cur]->compare(num) == 1)
				return cur;
			else if (cur == account_num - 1)
				return 0;
		}
	}
	void CreateAccounts(account* account)
	{
		if (account_num > MAX_ACCOUNT)
		{
			int sel_count = AccountCompare(account_num);
			if (sel_count != 0)
			{
				cout << "���� ID ���� ������ �Ұ����մϴ�." << endl;
				delete accounts[sel_count];
			}
		}
		else
		{
			account_num++;
		}
		//���� id ����
	}
	//�Ա�
	void DepositAccounts(int num,int money)
	{
		int sel_count = AccountCompare(num);
		if (sel_count == 0)
		{
			cout << "�ùٸ� ID �� �Է����ּ��� " << endl;
		}
		else
		{
			accounts[sel_count]->Deposit(money);
		}
	}
	//���
	void WithdrawAccounts(int num, int money)
	{
		int sel_count = AccountCompare(num);
		if (sel_count == 0)
		{
			cout << "�ùٸ� ID �� �Է����ּ��� " << endl;
		}
		else
		{
			accounts[sel_count]->Withdraw(money);
		}
	}
	//Ȯ��
	void ShowAllAccounts()
	{
		for (int cur = 0; cur < account_num; cur++)
		{
			accounts[cur]->CallAccount();
		}
	}
	//����
	void DeleteAccounts()
	{
		for (int cur = 0; cur < account_num; cur++)
		{
			delete accounts[cur];
		}
	}
};


int main(void)
{
	int num, in_num, money;
	char name[30];

	ControlBank bank;
	
	int account_num=0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			cout << " ���� ID : ";
			cin >> in_num;
			cout << " �̸�	  : ";
			cin >> name;
			cout << " �Աݾ�  : ";
			cin >> money;
			bank.CreateAccounts(new account(in_num, money, name));
		}
		else if (num == 2)
		{
			cout << "[�Ա�]" << endl;
			cout << "���� ID :";
			cin >> in_num;
			cout << "�Աݾ�:";
			cin >> money;
			bank.DepositAccounts(in_num, money);
		}
		else if (num == 3)
		{
			cout << "[���]" << endl;
			cout << "���� ID :";
			cin >> in_num;
			cout << "��ݾ�:";
			cin >> money;
			bank.WithdrawAccounts(in_num, money);
		}
		else if (num == 4)
		{
			bank.ShowAllAccounts
		}
		else if (num == 5)
		{
			bank.DeleteAccounts();
			break;
		}
		else
			cout << "�ùٸ� ���ڸ� �Է��ϼ��� " << endl;
	}
	return 0;
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