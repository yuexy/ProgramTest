 
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>  

using namespace std;

char getNum(char c)
{
	switch (c)
	{
	case 'A':
	case 'B':
	case 'C':
		return '2';

	case 'D':
	case 'E':
	case 'F':
		return '3';

	case 'G':
	case 'H':
	case 'I':
		return '4';

	case 'J':
	case 'K':
	case 'L':
		return '5';

	case 'M':
	case 'N':
	case 'O':
		return '6';

	case 'P':
	case 'R':
	case 'S':
		return '7';

	case 'T':
	case 'U':
	case 'V':
		return '8';

	case 'W':
	case 'X':
	case 'Y':
		return '9';

	default:
		return '0';
	}
}

string processString(string s)
{
	string res;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res.append(1, s[i]);
		else if (s[i] >= 'A' && s[i] <= 'Z')
			res.append(1, getNum(s[i]));
	}

	return res;
}

int times[10000000];
bool visit[10000000];
int sort_out[100000];

int main()
{
	int num;
	string s;
	string* phone;
	int ps = 0;

	bool flag = false;

	memset(times, 0, sizeof(times));
	memset(visit, false, sizeof(visit));

	cin >> num;

	phone = new string[num];

	for (int i = 0; i < num; i++)
	{
		int x = 0;
		cin >> s;
		phone[i] = processString(s);

		for (int j = 0; j < phone[i].length(); j++)
		{
			x = x * 10 + phone[i][j] - '0';
		}

		times[x]++;

		if (!visit[x] && times[x] >= 2)
		{
			flag = true;
			visit[x] = true;
			sort_out[ps++] = x;
		}
	}

	if (!flag)
		cout << "No duplicates." << endl;
	else
	{
		sort(sort_out,sort_out+ps);
		for(int i = 0; i < ps; i++)
		{
			cout << setfill('0') << setw(3) << sort_out[i] / 10000;
			cout << '-';
			cout << setfill('0') << setw(4) << sort_out[i] % 10000;
			cout << ' ' << times[sort_out[i]] << endl;
		}
	}

	return 0;
}