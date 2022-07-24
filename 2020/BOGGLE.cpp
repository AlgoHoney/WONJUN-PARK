/*
*	https://www.algospot.com/judge/problem/read/BOGGLE
*	å "�˰��� ���� �ذ� ���� 1" / ������ �� / �λ���Ʈ / p.150

*	Aaaaiiiiiee
*/
#include <iostream>
#include <string>
using namespace std;

// Make Variable
string board[5];	// Boggle Game Board.
int N;				// Number of words.
string* words;		// Words data we know.
const int dx[8] = { -1,	-1,	-1,	0,	0,	1,	1,	1 };
const int dy[8] = { -1,	0,	1,	-1,	1,	-1,	0,	1 };

bool hasWord(int x, int y, const string& word);

int main(void)
{
	int C;			// the number of testcase
	cin >> C;
	while (C--)
	{
		// Init
		for (int i = 0; i < 5; i++)
			cin >> board[i];

		cin >> N;

		words = new string[N];
		for (int i = 0; i < N; i++)
			cin >> words[i];

		// Print Result
		for (int i = 0; i < N; i++)
		{
			cout << words[i];
			for (int x = 0; x < 5; x++)
				for (int y = 0; y < 5; y++)
				{
					if (hasWord(x, y, words[i]))
					{
						cout << " YES" << endl;
						x = 5; y = 5;	// break;
					}
					else if (x == 4 && y == 4)
						cout << " NO" << endl;
				}
		}

		// Free Memory
		delete[]words;
	}

	return 0;
}

bool inRange(int x, int y)
{
	if (x < 0 || x > 4)	return true;
	if (y < 0 || y > 4)	return true;
	
	return false;
}

bool hasWord(int x, int y, const string& word)
{
	// ���� ��� 1 : ���� ��ġ�� ���� ���̸� ������ ����
	if (!inRange(x, y)) return false;

	// ���� ��� 2 : ù ���ڰ� ��ġ���� ������ ����
	if (board[y][x] != word[0])	return false;
	// ���� ��� 3 : �ܾ� ���̰� 1�̸� ����
	if (word.size() == 1)	return true;

	// ������ ���� ĭ�� �˻��Ѵ�.
	for (int direction = 0; direction < 8; direction++)
	{
		int nextY = y + dy[direction], nextX = x + dx[direction];
		// ���� ĭ�� ���� �ȿ� �ִ���, ù ���ڴ� ��ġ�ϴ��� Ȯ���� �ʿ䰡 ����.
		if (hasWord(nextX, nextY, word.substr(1)))
			return true;
	}

	return false;
}