#pragma once
#define MAX_ACCOUNT 5
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
	account(int num, int mon, char* nam);
	account(account &copy);
	virtual void CallAccount()const;
	int compare(int num);
	virtual void Deposit(int mon);
	void Withdraw(int mon);
	int ReturnId();
	~account();
};
class NormalAccount : public account
{
private:
	double interestRate;
public:
	NormalAccount(int num, int mon, char* nam, double rate);
	void Deposit(int mon);
	void CallAccount() const;
};

class HighCreditAccount : public account
{
private:
	double interestRate;
	char specialRate;
public:
	HighCreditAccount(int num, int mon, char* nam, double rate, char special);
	void Deposit(int mon);
	void CallAccount() const;
};

class BoundCheckPointArray
{
private:
	account** accounts;
	int acclen;
public:
	BoundCheckPointArray(int len);
	account* operator[](int len);
	void AccountCreate(int num,account* account);
	~BoundCheckPointArray();
};

class ControlBank
{
private:
	BoundCheckPointArray accounts;
	int account_num;
public:
	ControlBank();
	int AccountCompare(int num);
	void CreateAccounts(account* account);
	//입금
	int DepositAccounts(int num, int money);
	//출금
	int WithdrawAccounts(int num, int money);
	//확인
	void ShowAllAccounts();
	//삭제
	void DeleteAccounts();
};


class AccountException
{
public:
	virtual void ShowResult() = 0;
};

class DepositException : public AccountException
{
private:
	int myMoney;
public:
	DepositException(int money);
	void ShowResult();
};

class WithdrawException : public AccountException
{
private:
	int myMoney;
public:
	WithdrawException(int money);
	void ShowResult();
};
