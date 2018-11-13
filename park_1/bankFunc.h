#pragma once

#define MAX_ACCOUNT 100
#include <iostream>
#include <stdlib.h>

using namespace std;

class account
{
	int money;
	int number;
	char* name;

	account();
	void CallAccount();
	void compare(int num, int count);
	void Deposit(int money);
	int Withdraw(int money);
	~account();
	
}infor;

