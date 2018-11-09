#include"car.h"

using namespace std;

void Car::InitMembers(const char* id, int fuel)
{
	strcpy(gamerID, id);
	fuelGauge = fuel;
	curSpeed = 0;
}
void Car::ShowCarState()
{
	cout << "소유자 :" << gamerID << endl;
	cout << "연료량 :" << fuelGauge << endl;
	cout << "속  도 :" << curSpeed << endl;
}
void Car::Accel()
{
	//연료량 체크
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;
	//최고 속도 체크
	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if (curSpeed - CAR_CONST::BRK_STEP < 0)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}