#include"bank.h"
#include"AccountArray.h"

class BoundCheckPointArray
{
private:
	account* acc;
	int acclen;
public:
	BoundCheckPointArray(int len) : acclen(len)
	{
		acc = new account[len];
	}
	BoundCheckPointArray& operator[](int len)
	{

	}
	~BoundCheckPointArray()
	{
		delete[] acc;
	}
};

class AccountException
{
public:
	virtual void ShowResult()=0;
};

class DepositException : public AccountException
{
private:
	int myMoney;
public:
	DepositException(int money) : myMoney(money)
	{}
	void ShowResult()
	{
		cout << "입금 오류 : " << myMoney << "를 입금할 수 없습니다." << endl;
	}
};

class WithdrawException : public AccountException
{
private:
	int myMoney;
public:
	WithdrawException(int money) : myMoney(money)
	{}
	void ShowResult()
	{
		cout << "출금 오류 : " << myMoney << "를 출금할 수 없습니다." << endl;
	}
};


int main(void)
{
	int num, num2, in_num, money;
	double rate;
	char special;
	char name[30];

	ControlBank bank;
	
	int account_num=0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			cout << "보통 계좌 : 1		신용 계좌 : 2        ::" ;
			cin >> num2;
				
			switch (num2)
			{	
				case 1:
					cout << " 계좌 ID : ";
					cin >> in_num;
					cout << " 이름	  : ";
					cin >> name;
					cout << " 입금액  : ";
					cin >> money;
					cout << " 이율    : ";
					cin >> rate;
					bank.CreateAccounts(new NormalAccount(in_num, money, name, rate));
					break;
				
				case 2:
					cout << " 계좌 ID : ";
					cin >> in_num;
					cout << " 이름	  : ";
					cin >> name;
					cout << " 입금액  : ";
					cin >> money;
					cout << " 이율    : ";
					cin >> rate;
					cout << " 등급    : ";
					cin >> special;
					bank.CreateAccounts(new HighCreditAccount(in_num, money, name,rate,special));
					break;

			}
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
			bank.ShowAllAccounts();
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

