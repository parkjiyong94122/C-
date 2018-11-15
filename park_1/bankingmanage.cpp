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
	int Withdraw(int mon)
	{
		if (money < mon)
			return 0;
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
	void CreateAccount(int num, int money, char* name)
	{
		accounts[account_num] = new account(num, money, name);
		account_num++;
	}
};


int main(void)
{
	int num, in_num, money;
	char name[30];
	
	int account_num=0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			if (account_num < MAX_ACCOUNT)
			{
				cout << " ���� ID : ";
				cin >> in_num;
				cout << " �̸�	  : ";
				cin >> name;
				cout << " �Աݾ�  : ";
				cin >> money;

				accounts[account_num] = new account(in_num,money,name);
				
				for (int cur = 0; cur < account_num; cur++)
				{
					if (accounts[cur]->compare(in_num) == 1)
					{
						delete accounts[account_num];
						account_num--;
						cout << "���� ID ���� ������ �Ұ����մϴ�." << endl;
					}
				}
				account_num++;
			}
			else
				cout << "�� �̻� ���»����� �Ұ����մϴ�." << endl;
		}
		else if (num == 2)
		{
			cout << "[�Ա�]" << endl;
			cout << "���� ID :";
			cin >> in_num;
			cout << "�Աݾ�:";
			cin >> money;
			for (int cur = 0; cur < account_num; cur++)
			{
				if (accounts[cur]->compare(in_num) == 1)
					accounts[cur]->Deposit(money);

				else if (cur == account_num - 1)
					cout << "�ùٸ� ID �� �Է����ּ��� ";
			}
		}
		else if (num == 3)
		{
			cout << "[���]" << endl;
			cout << "���� ID :";
			cin >> in_num;
			cout << "��ݾ�:";
			cin >> money;
			for (int cur = 0; cur < account_num; cur++)
			{
				if (accounts[cur]->compare(in_num) == 1)
				{ 
					if (accounts[cur]->Withdraw(money) == 0)
						cout << "�ݾ��� �����մϴ�." << endl;
				}
				else if (cur == account_num - 1)
					cout << "�ùٸ� ID �� �Է����ּ��� ";
			}
		}
		else if (num == 4)
		{
			for (int cur = 0; cur < account_num; cur++)
			{
				accounts[cur]->CallAccount();
			}
		}
		else if (num == 5)
		{
			for (int cur = 0; cur < account_num; cur++)
			{
				delete accounts[cur];
			}
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