#include<iostream>

using namespace std;

/*
	- 나는 과일 장수에게 5000원어치의 사과를 구매한다.
	- Object 후보
		과일 장수, 과일 구매자
*/

class FruitSeller
{
	//사과 재고 수량, 사과 단가, 판매 수익
private:

	const int APPLE_PRICE;// 이후 변하지 않으므로 상수로 지정
	int	NumOfApples, MyMoney;

public:
	//변수 초기화 -> 생성자
	//멤버 이니셜라이징
	FruitSeller(int price, int num, int money) : APPLE_PRICE(price)//, NumOfApples(num), MyMoney(money)
	{
		//APPLE_PRICE = price;
		NumOfApples = num;
		MyMoney = money;
	}
	//사과 판매 함수
	int SalesApples(int money)
	{
		int num = money / APPLE_PRICE;
		NumOfApples -= num;
		MyMoney += money;

		return num;
	}
	//현재상태 출력
	//함수의 상수화- 함수내에서 변경불가능.
	void ShowSaleResult() const
	{
		cout << "사과 재고 : " << NumOfApples <<endl;
		cout << "판매 수익 : " << MyMoney << endl;
	}

};

class FruitBuyer
{
private:
	//잔액, 구입한 사과의 수량, 
	int MyMoney, NumOfApple;

public:
	//변수 초기화
	FruitBuyer(int money)
	{
		MyMoney = money;
		NumOfApple = 0;
	}
	//사과 구입함수
	//객체간의 거래
	void BuyApple(FruitSeller &seller, int money)
	{
		NumOfApple += seller.SalesApples(money);
		MyMoney -= money;
	}
	//현재상태 출력
	//함수의 상수화- 함수내에서 변경불가능.
	void ShowBuyResult() const
	{
		cout << "잔액      : " << MyMoney << endl;
		cout << "사과 수량 : " << NumOfApple << endl;
	}
};

int main(void)
{
	
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);

	// 사고 판매 및 구매 거래
	buyer.BuyApple(seller, 2000);


	cout << "과일 판매자 현황 " << endl;
	seller.ShowSaleResult();
	cout << "과일 구매자 현황 " << endl;
	buyer.ShowBuyResult();

	return 0;
}