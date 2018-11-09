#ifndef _CAR_H_
#define _CAR_H_
#include <iostream>
#include <cstring>
namespace CAR_CONST
{
	//const int ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 20, ACC_STEP = 10, BRK_STEP = 10;
	enum
	{
	ID_LEN = 20,
	MAX_SPD = 200,
	FUEL_STEP = 20,
	ACC_STEP = 10,
	BRK_STEP = 10,
	};
}
class Car
{

private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(const char* id, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

#endif