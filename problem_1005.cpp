#include <iostream>

using namespace std;

int num;
int* w;
int* v;
int c;
int** value;

int getValue()
{
	for (int i = 0; i <= num; i++)
		value[i][0] = 0;

	for (int i = 0; i <= c; i++)
		value[0][i] = 0;

	for (int i = 1; i <= num; i++)
		for (int j = 0; j <= c; j++)
			if (j < w[i])
				value[i][j] = value[i - 1][j];
			else
				value[i][j] = value[i - 1][j] > (value[i - 1][j - w[i]] + v[i]) ? value[i - 1][j] : (value[i - 1][j - w[i]] + v[i]);

	return value[num][c];
}

int main()
{
	while(cin >> num)
	{
		w = new int[num + 1];
		v = new int[num + 1];

		w[0] = 0;
		v[0] = 0;
		for (int i = 1; i <= num; i++)
		{
			cin >> w[i] >> v[i];
		}

		cin >> c;

		value = new int*[num + 1];
		for (int i = 0; i < c; i++)
		{
			value[i] = new int[c + 1];
		}

		cout << getValue();

		delete[] w;
		delete[] v;
		// for (int i = 0; i <= num; i++)
		// 	delete[] value[i];
		// delete[] value;
	}

	return 0;
}