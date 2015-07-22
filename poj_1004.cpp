#include <iostream>

using namespace std;

int main()
{
	double sum = 0.00;
	double h;

	for (int i = 0; i < 12; i++)
	{
		cin >> h;
		sum += h;
	}

	cout << "$" << sum / 12 << endl;

	return 0;
}