#pragma once

#define MAX_ACCOUNT 100
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct customer
{
	int money;
	int number;
	char name[20];
}infor;

void call_menu();
infor *create_account();
void Call_Account(infor* account);
infor *compare(infor** account, int num, int count);
void Deposit(infor* account, int money);
int Withdraw(infor* account, int money);
void Delete_account(infor** account, int count);