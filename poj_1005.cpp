#include <iostream>

using namespace std;

int main()
{
	int num;
	double x, y, size;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		size = (x * x + y * y) * 3.14 * 0.5;
		cout << "Property " << i + 1 << ": This property will begin eroding in year " << (int)(size / 50) + 1 << "." << endl;
	}

	cout << "END OF OUTPUT." << endl;

	return 0;
}