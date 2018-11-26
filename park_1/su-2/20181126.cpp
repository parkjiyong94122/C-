#include<iostream>
#include<cstring>

using namespace std;

template <typename T>

class Point
{
private:
	T xPos, yPos;
public:
	Point(T x=0, T y=0) : xPos(x), yPos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xPos << ". " << yPos << ']' << endl;
	}
};

int main(void)
{
	//클래스 템플릿

	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(5.2, 6.1);
	pos2.ShowPosition();

	Point<char> pos2('A', 'B');
	pos2.ShowPosition();

	return 0;
}