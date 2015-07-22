#include <iostream>

using namespace std;

int** height;
int** value;
int X;
int Y;

void getValue();
int getIj(int x, int y);

int main()
{
	cin >> X >> Y;
	height = new int*[X];
	value = new int*[X];

	for (int i = 0; i < X; i++)
	{
		height[i] = new int[Y];
		value[i] = new int[Y];

		for (int j = 0; j < Y; j++)
		{
			cin >> height[i][j];
			value[i][j] = -1;
		}
	}

	getValue();

	int max = value[0][0];

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (value[i][j] > max)
				max = value[i][j];
		}
	}

	cout << max << endl;

	return 0;
}

void getValue()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			//get value for every value[i][j]
			value[i][j] = getIj(i, j);
		}
	}
}

int getIj(int x, int y)
{
	int l, r, u, d;

	if (x < 0)
		return -1;

	if (y < 0)
		return -1;

	if (value[x][y] != -1)
		return value[x][y];

	if (x - 1 >= 0 && height[x][y] > height[x - 1][y])
		l = getIj(x - 1, y);
	else
		l = 0;

	if (x + 1 < X && height[x][y] > height[x + 1][y])
		r = getIj(x + 1, y);
	else
		r = 0;

	if (y - 1 >= 0 && height[x][y] > height[x][y - 1])
		u = getIj(x, y - 1);
	else
		u = 0;

	if (y + 1 < Y && height[x][y] > height[x][y + 1])
		d = getIj(x, y + 1);
	else
		d = 0;

	int max = l;

	if (r > max)
		max = r;
	if (u > max)
		max = u;
	if (d > max)
		max = d;

	return max + 1;
}