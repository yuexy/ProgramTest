#include <iostream>
#include <string>

using namespace std;

string pow(string s, int i);
string mul(string s1, string s2);
string trimRes(string s);

int main()
{
	string s;
	int i;

	while (cin >> s >> i)
	{
		string res = pow(s, i);
		cout << trimRes(res) << endl;
	}
	
	return 0;
}

string pow(string s, int index)
{
	if (index == 1)
		return s;

	if (index == 2)
		return mul(s, s);

	int i = index / 2;
	int j = index % 2;

	if (j == 1)
		return mul(pow(pow(s, i), 2), s);
	else
		return pow(pow(s, i), 2);
}

string mul(string s1, string s2)
{
	string res = "";
	
	int index_1 = s1.length() - 1;
	int index_2 = s2.length() - 1;

	int position_1 = index_1;
	int position_2 = index_2;

	if (s1.find('.') != string::npos)
	{
		position_1 = s1.find('.');
		s1 = s1.erase(position_1, 1);
		index_1 = s1.length() - 1;
	}

	if (s2.find('.') != string::npos)
	{
		position_2 = s2.find('.');
		s2 = s2.erase(position_2, 1);
		index_2 = s2.length() - 1;
	}

	int* r = new int[s1.length() + s2.length()];
	int index_r = s1.length() +s2.length() - 1;

	int last = 0;

	for (int i = 0; i < index_r + 1; i++)
		r[i] = 0;

	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			int s1_int = s1[index_1 - i] - '0';
			int s2_int = s2[index_2 - j] - '0';

			int sum = r[index_r - i - j] + last + s1_int * s2_int;

			r[index_r - i - j] = sum % 10;
			last = sum / 10;
		}
		if (last != 0)
		{
			r[index_r - i - s2.length()] = last;
			last = 0;
		}
	}

	int w = (index_1 - position_1) + (index_2 - position_2);

	cout << res;

	for (int i = 0; i < index_r + 1; i++)
	{
		if (i == index_r - w - 1)
			res.append(".", 1);
		res.append(1, r[i] + '0');
	}

	return res;
}

string trimRes(string s)
{
	int it = 0, end = s.size() - 1;
	while (s.at(it) == '0') it++;
	if (s.find('.') != string::npos)
	{
		while(s.at(end) == '0')
			end--;
		if(s.at(end) == '.') end--;
		
	}	
	return s.substr(it, end - it + 1);	
}
