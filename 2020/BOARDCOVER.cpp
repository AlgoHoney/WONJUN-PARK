/*
*	https://www.algospot.com/judge/problem/read/BOARDCOVER
*	å "�˰��� ���� �ذ� ���� 1" / ������ �� / �λ���Ʈ / p.159

*	Aaaaiiiiiee
*/
/*
*	indexboundexception, (y,x) �� �ε��� ���� ����
*	L���� ���� ��츦 ��� ������ ����(4->8->12). but å �����ϸ� ������ 12���� �ƴ�.
*/
#include <iostream>
using namespace std;
#define L_CASES 12

enum { BLACK, WHITE };

const int dx[L_CASES][2] = {
	{ 0, 1 },
	{ -1, 1 },
	{ -1, 0 },
	{ -1, -1 },

	{ 0, -1 },
	{ -1, -1 },
	{ 0, 1 },
	{ 1, 1 },

	{1, 0},
	{0, 1},
	{0, 1},
	{-1, 0}
};
const int dy[L_CASES][2] = {
	{1, 1},
	{ 0, 1 },
	{ -1, -1 },
	{ 0, 1 },

	{ 1, 1 },
	{ 0, -1 },
	{ -1, -1 },
	{ 0, 1 },

	{0, 1},
	{-1, 0},
	{-1, 0},
	{0, 1}
};
int** board;
int H, W;
int result;

void couldCover();

int main(void)
{
	int C;	cin >> C;
	while (C--)
	{
		/* Input Data */
		cin >> H >> W;
		board = new int*[H];
		for (int i = 0; i < H; i++)
		{
			board[i] = new int[W];
			for (int j = 0; j < W; j++)
			{
				char tmp;	cin >> tmp;
				if (tmp == '#')	board[i][j] = BLACK;
				else if (tmp == '.')	board[i][j] = WHITE;
			}
		}

		/* Search */
		couldCover();
		/* Print Result */
		cout << result << endl;

		/* Initial Variable */
		result = 0;

		/* Memory Free */
		for (int i = 0; i < H; i++)
			delete board[i];
		delete[]board;
	}

	return 0;
}

void couldCover()
{
	/* Find First White Board */
	int firstWhite = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			if (board[i][j] == WHITE)
			{
				firstWhite = (i * W) + j;
				break;
			}
		if (firstWhite != -1)	break;
	}

	/* If board covered by L already, return. ������� 1 */
	if (firstWhite == -1) { result++;	return; }

	/* Make Variation 'firstWhite' into index of 2-dimension */
	int curY = firstWhite / W, curX = firstWhite - (curY*W);
	
	/* Put L for L_CASES */
	for (int cases = 0; cases < L_CASES; cases++)
	{
		/* Check whether I can put L or not */
		bool isAllWhite = true;
		for (int j = 0; j < 2; j++)
		{
			int moveY = curY + dy[cases][j], moveX = curX + dx[cases][j];

			/* ����ó�� */
			if (moveY < 0 || moveY >= H) { isAllWhite = false;	continue; }
			if (moveX < 0 || moveX >= W) { isAllWhite = false;	continue; }

			if (board[moveY][moveX] == BLACK)
				isAllWhite = false;
		}

		/* If I can put L */
		if (isAllWhite)
		{
			int coverY[3] = { curY, curY + dy[cases][0], curY + dy[cases][1] };
			int coverX[3] = { curX, curX + dx[cases][0], curX + dx[cases][1] };

			for (int l_number = 0; l_number < 3; l_number++)
				board[coverY[l_number]][coverX[l_number]] = BLACK;

			couldCover();	// dfs

			for (int l_number = 0; l_number < 3; l_number++)
				board[coverY[l_number]][coverX[l_number]] = WHITE;
		}
	}
	
	return;
}