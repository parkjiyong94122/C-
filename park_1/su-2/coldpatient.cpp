#include"coldpatient.h"

using namespace std;

//Äà¹° Ä¸½¶
void SinivelCap::Take()
{
	cout << "Äà¹°ÀÌ ¸Ü½À´Ï´Ù." << endl;
}

//ÀçÃ¤±â Ä¸½¶
void  SneezeCap::Take()
{
	cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << endl;
}

//ÄÚ¸·Èû Ä¸½¶
void SnuffleCap::Take()
{		
	cout << "ÄÚ°¡ ¶Õ¸³´Ï´Ù." << endl;
}

void AllCap::Take()
{	
	sin.Take();
	sne.Take();
	snu.Take();
}

//Äà¹°¾à º¹¿ë
void ColdPatient::TakeSinivelCap(SinivelCap &cap)
{
	cap.Take();
}

//ÀçÃ¤±â¾à º¹¿ë
void ColdPatient::TakeSneezeCap(SneezeCap &cap)
{
	cap.Take();
}

//ÄÚ¸·Èû¾à º¹¿ë
void ColdPatient::TakeSnuffleCap(SnuffleCap &cap)
{
	cap.Take();
}

//¸ğµç¾à º¹¿ë
void ColdPatient::TakeCap(AllCap &cap)
{
	cap.Take();
}
