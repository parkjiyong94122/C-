#include<iostream>

using namespace std;

/*
	- ���� ���� ������� 5000����ġ�� ����� �����Ѵ�.
	- Object �ĺ�
		���� ���, ���� ������
*/

class FruitSeller
{
	//��� ��� ����, ��� �ܰ�, �Ǹ� ����
private:

	const int APPLE_PRICE;// ���� ������ �����Ƿ� ����� ����
	int	NumOfApples, MyMoney;

public:
	//���� �ʱ�ȭ -> ������
	//��� �̴ϼȶ���¡
	FruitSeller(int price, int num, int money) : APPLE_PRICE(price)//, NumOfApples(num), MyMoney(money)
	{
		//APPLE_PRICE = price;
		NumOfApples = num;
		MyMoney = money;
	}
	//��� �Ǹ� �Լ�
	int SalesApples(int money)
	{
		int num = money / APPLE_PRICE;
		NumOfApples -= num;
		MyMoney += money;

		return num;
	}
	//������� ���
	//�Լ��� ���ȭ- �Լ������� ����Ұ���.
	void ShowSaleResult() const
	{
		cout << "��� ��� : " << NumOfApples <<endl;
		cout << "�Ǹ� ���� : " << MyMoney << endl;
	}

};

class FruitBuyer
{
private:
	//�ܾ�, ������ ����� ����, 
	int MyMoney, NumOfApple;

public:
	//���� �ʱ�ȭ
	FruitBuyer(int money)
	{
		MyMoney = money;
		NumOfApple = 0;
	}
	//��� �����Լ�
	//��ü���� �ŷ�
	void BuyApple(FruitSeller &seller, int money)
	{
		NumOfApple += seller.SalesApples(money);
		MyMoney -= money;
	}
	//������� ���
	//�Լ��� ���ȭ- �Լ������� ����Ұ���.
	void ShowBuyResult() const
	{
		cout << "�ܾ�      : " << MyMoney << endl;
		cout << "��� ���� : " << NumOfApple << endl;
	}
};

int main(void)
{
	
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);

	// ��� �Ǹ� �� ���� �ŷ�
	buyer.BuyApple(seller, 2000);


	cout << "���� �Ǹ��� ��Ȳ " << endl;
	seller.ShowSaleResult();
	cout << "���� ������ ��Ȳ " << endl;
	buyer.ShowBuyResult();

	return 0;
}