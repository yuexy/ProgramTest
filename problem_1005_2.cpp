#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int* value;
	int* size;
	int* point;
	int num;
	int c;

	while (cin >> num)
	{
		size = new int[num];
		point = new int[num];

		for (int i = 0; i < num; i++)
		{
			cin >> size[i] >> point[i];
		}

		cin >> c;

		value = new int[c + 1];
		for (int i = 0; i <= c; i++)
		{
			value[i] = 0;
		}

		for (int i = 0; i < num; i++)
		{
			for (int j = c; j >= size[i]; j--)
			{
				value[j] = value[j] > (value[j - size[i]] + point[i]) ? value[j] : (value[j - size[i]] + point[i]);
			}
		}

		cout << value[c] << endl;

		delete[] value;
		delete[] size;
		delete[] point;
	}

	return 0;
}