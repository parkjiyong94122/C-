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
		cout << "계좌ID  :" << number << endl << "이름 :" << name << endl << "입금액 :" << money << endl;
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
			cout << "잔액이 부족합니다." << endl;
		else
			money -= mon;
	}
	~account()
	{
		cout << "삭제됨 " << endl;
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
		cout << "이자율 : " << interestRate << endl;
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
		cout << "이자율 : " << interestRate << endl;
		cout << "고객등급 : " << specialRate << endl;
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
				cout << "동일 ID 계좌 생성이 불가능합니다." << endl;
				delete accounts[sel_count];
			}
		}
		else
		{
			account_num++;
		}
		//동일 id 제외
	}
	//입금
	void DepositAccounts(int num,int money)
	{
		int sel_count = AccountCompare(num);
		if (sel_count == 0)
		{
			cout << "올바른 ID 를 입력해주세요 " << endl;
		}
		else
		{
			accounts[sel_count]->Deposit(money);
		}
	}
	//출금
	void WithdrawAccounts(int num, int money)
	{
		int sel_count = AccountCompare(num);
		if (sel_count == 0)
		{
			cout << "올바른 ID 를 입력해주세요 " << endl;
		}
		else
		{
			accounts[sel_count]->Withdraw(money);
		}
	}
	//확인
	void ShowAllAccounts()
	{
		for (int cur = 0; cur < account_num; cur++)
		{
			accounts[cur]->CallAccount();
		}
	}
	//삭제
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
			cout << " 계좌 ID : ";
			cin >> in_num;
			cout << " 이름	  : ";
			cin >> name;
			cout << " 입금액  : ";
			cin >> money;
			bank.CreateAccounts(new account(in_num, money, name));
		}
		else if (num == 2)
		{
			cout << "[입금]" << endl;
			cout << "계좌 ID :";
			cin >> in_num;
			cout << "입금액:";
			cin >> money;
			bank.DepositAccounts(in_num, money);
		}
		else if (num == 3)
		{
			cout << "[출금]" << endl;
			cout << "계좌 ID :";
			cin >> in_num;
			cout << "출금액:";
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
			cout << "올바른 숫자를 입력하세요 " << endl;
	}
	return 0;
}

void call_menu()
{
	cout << "---------Menu---------" << endl;
	cout << "1. 계좌 개설 " << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;

	cout << "선택 : ";
}