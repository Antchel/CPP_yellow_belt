#include <iostream>

using namespace std;

int main()
{
	int qty = 0, dsty = 0;
	cin >> qty >> dsty;
	int mass=0;
	while (qty--)
	{
		int w, d, h;
		cin >> w >> h >> d;
		mass += dsty * w * h * d;
	}
	cout << mass << endl;
}