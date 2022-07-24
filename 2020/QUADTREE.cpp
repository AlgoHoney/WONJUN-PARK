/*
*	https://www.algospot.com/judge/problem/read/QUADTREE
*	å "�˰��� ���� �ذ� ���� 1" / ������ �� / �λ���Ʈ / p.189

*	Aaaaiiiiiee
*	2020.02.05
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define LOCAL
#pragma warning(disable : 4996)

string input;

string QuadTree();
void swap(string&, string&);

int main(void)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int C;	cin >> C;
	while (C--)
	{
		/* Init Data */
		cin >> input;

		/* Print Result */
		cout << QuadTree() << endl;
	}

	return 0;
}

string QuadTree()
{
	vector<string> v;

	while (true)
	{
		// �������� 1
		if (v.size() == 4)
		{
			swap(v[0], v[2]);
			swap(v[1], v[3]);
			v[0].insert(0, "x");
			break;
		}
		// �������� 2 : input�� 4�� �̻����� �̷������ ���� ���
		if (input.empty())	break;

		char cur = input[0];	input.erase(0, 1);
		if (cur == 'b' || cur == 'w')
			v.push_back(string("") + cur);
		else if (cur == 'x')
			v.push_back(QuadTree());
	}

	/* Combine String */
	string str = "";
	for (string e : v)
		str += e;

	return str;
}

void swap(string& v1, string& v2)
{
	string tmp = v2;
	v2 = v1;
	v1 = tmp;
}