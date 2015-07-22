#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Result
{
public:
	string s;
	int num;

	Result()
	{
		num = -1;
	}
};

class Node
{
public:
	char n;
	bool leaf;
	int num;
	Node* children[10];
	string s;

	Node(char i, bool b)
	{
		n = i;
		leaf = b;
		num = 0;

		for (int i = 0; i < 10; i++)
			children[i] = NULL;
	}
};

class TrieTree
{
public:
	Node* root;

	TrieTree();
	void Insert(string s);
	int Search(string s);
	Result* getRes(int& num);
};

TrieTree::TrieTree()
{
	root = new Node('a', false);
	root->s = "a";
}

void TrieTree::Insert(string s)
{
	Node* p = root;

	for (int i = 0; i < s.length(); i++)
	{
		if (p->children[s[i] - '0'] == NULL)
		{
			p->children[s[i] - '0'] = new Node(s[i], (i == s.length() - 1) ? true : false);
			p->children[s[i] - '0']->s = p->s;
			p->children[s[i] - '0']->s.append(1, s[i]);
		}

		p->children[s[i] - '0']->num++;
		p = p->children[s[i] - '0'];
	}
}

int TrieTree::Search(string s)
{
	Node* p = root;

	for (int i = 0; i < s.length(); i++)
	{
		if (p->children[s[i] - '0'] != NULL)
			p = p->children[s[i] - '0'];
		else
			return -1;
	}

	return p->num;
}

Result* TrieTree::getRes(int& num)
{
	Result* res = new Result[num];
	Node* p = root;
	int index = 0;
	stack<Node*> nodeStack;

	for (int i = 9; i >= 0; i--)
	{
		if (root->children[i] != NULL)
			nodeStack.push(root->children[i]);
	}

	while (!nodeStack.empty())
	{
		p = nodeStack.top();
		if (p->leaf)
		{
			res[index].s = p->s.substr(1);
			res[index].num = p->num;
			index++;
		}
		nodeStack.pop();

		for (int i = 9; i >= 0; i--)
		{
			if (p->children[i] != NULL)
				nodeStack.push(p->children[i]);
		}
	}

	num = index;
	return res;
}

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

string getResNumber(string s)
{
	string res;

	for (int i = 0; i < s.length(); i++)
	{
		res.append(1, s[i]);
		if (i == 2)
		{
			res.append(1, '-');
		}
	}

	return res;
}

int main()
{
	int num;
	string s;
	string* phone;
	int* numbers;

	TrieTree* tt = new TrieTree();

	cin >> num;

	phone = new string[num];
	numbers = new int[num];

	for (int i = 0; i < num; i++)
	{
		cin >> s;
		phone[i] = processString(s);
		tt->Insert(phone[i]);

		numbers[i] = 0;
	}

	Result* res = tt->getRes(num);

	bool flag = false;
	for (int i = 0; i < num; i++)
	{
		if (res[i].num > 1)
		{
			cout << getResNumber(res[i].s) << " " << res[i].num << endl;
			flag = true;
		}
	}

	if (!flag)
		cout << "No duplicates." << endl;

	return 0;
}