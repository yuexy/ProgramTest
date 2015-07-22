#include <iostream>

using namespace std;

int index = 0;
int P = 23;
int E = 28;
int I = 33;
int B = 21252;

int hello1(int p, int e, int i)
{
	int x = i;

	while (!((x - p) % P == 0 && (x - e) % E == 0))
	{
		x += I;
	}

	if (x <= 0)
		x += B;

	return x;
}

int hello2(int p, int e, int i)
{
	p %= P;
	e %= E;
	i %= I;

	int x = i;

	while (!((x - p) % P == 0 && (x - e) % E == 0))
	{
		x += I;
	}

	if (x <= 0)
		x += B;

	return x;
}

int main()
{
	int x;

	int p, e, i, d;

	for (int i = 0; i < 366; i++)
	{
		for (int j = 0; j < 366; j++)
		{
			for (int k = 0; k < 366; k++)
			{
				if (hello1(i, j, k) != hello2(i, j, k))
				{
					cout << i << endl;
					cout << j << endl;
					cout << k << endl;
					cout << hello1(i, j, k) << endl;
					cout << hello2(i, j, k) << endl;
					goto A;
				}
			}
		}
	}

	A:

		//cout << "Case " << index << ": the next triple peak occurs in " << x << " days." << endl;

	return 0;
}