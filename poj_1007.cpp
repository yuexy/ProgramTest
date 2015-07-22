#include <iostream>
#include <string>

using namespace std;

class Pairs
{
public:
	int pos;
	int value;
};

void swapPairs(Pairs& p1, Pairs& p2)
{
	int p = p1.pos;
	int v = p1.value;

	p1.pos = p2.pos;
	p1.value = p2.value;

	p2.pos = p;
	p2.value = v;
}

int partition(Pairs* ps, int s, int e)
{
	int x = ps[e].value;
	int i = s - 1;

	for (int j = s; j < e; j++)
	{
		if (ps[j].value <= x)
		{
			i++;
			swapPairs(ps[i], ps[j]);
		}
	}
	swapPairs(ps[i + 1], ps[e]);

	return i + 1;
}

void Q_sort(Pairs* ps, int s, int e)
{
	int q;
	if (s < e)
	{
		q = partition(ps, s, e);
		Q_sort(ps, s, q - 1);
		Q_sort(ps, q + 1, e);
	}
}

int getWight(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	default:
		return c - 'A';
	}
}

int initArray(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		a[i] = 0;
	}
}

int main()
{
	Pairs* nums;
	int count[4];

	int len, n;
	string dna;
	string* dnas;

	cin >> len >> n;

	nums = new Pairs[n];
	dnas = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> dna;
		dnas[i] = dna;

		initArray(count, 4);

		int sum = 0;

		for (int k = len - 1; k > -1; k--)
		{
			int pos = getWight(dna[k]);
			count[pos]++;
			for (int j = 0; j < pos; j++)
			{
				sum += count[j];
			}
		}

		nums[i].value = sum;
		nums[i].pos = i;
	}

	Q_sort(nums, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << dnas[nums[i].pos] << endl;
	}


	return 0;
}