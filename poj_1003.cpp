#include <iostream>

using namespace std;

int main()
{
	double a;
	double n = 2;
	double sum = 0;

	while (cin >> a && a != 0.00)
	{
		while (sum < a)
		{
			sum += (1.0 / n);
			n++;
		}

		cout << n - 2 << " card(s)" << endl;

		sum = 0;
		n = 2;
	}

	return 0;
}