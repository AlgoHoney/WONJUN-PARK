/*
*	https://www.algospot.com/judge/problem/read/PICNIC
*	å "�˰��� ���� �ذ� ���� 1" / ������ �� / �λ���Ʈ / p.150

*	Aaaaiiiiiee
*	4C2 * 2C2 / 2! ������ pair�� �ߺ��� ����� ����. Ȯ���� �̿��� 2!�� ���Ƿ� �����ִ� ������� Ǯ����.
*/
#include <iostream>
using namespace std;

int result;
bool** friends;
int N;	// �л� ��
int C, M;	// C : �׽�Ʈ���̽� ��, M : ģ�� ���� ��
bool* students;

int Factorial(int n);
void MakeFriends(int n);

int main(void)
{
	// Init
	cin >> C;
	while (C--)
	{
		cin >> N >> M;

		friends = new bool*[N];
		for (int i = 0; i < N; i++)
		{
			friends[i] = new bool[N];
			fill(&friends[i][0], &friends[i][N], false);
		}
		students = new bool[N];
		fill(&students[0], &students[N], true);

		for (int i = 0; i < M; i++)
		{
			int row, col;	cin >> row >> col;
			friends[row][col] = friends[col][row] = true;
		}

		// Calculate
		MakeFriends(N);
		// Print Result
		cout << result / Factorial(N / 2) << endl;

		// �޸� �ʱ�ȭ
		for (int i = 0; i < N; i++)
			delete friends[i];
		delete[]friends;
		delete[]students;

		// �������� �ʱ�ȭ
		result = 0;
	}

	return 0;
}

void MakeFriends(int n)
{
	// �������� : �л� ���� 0�̸�, true
	if (n == 0) { result++; return; }

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (students[i] && students[j] && friends[i][j])
			{
				friends[i][j] = friends[j][i] = false;
				students[i] = students[j] = false;

				MakeFriends(n - 2);

				friends[i][j] = friends[j][i] = true;
				students[i] = students[j] = true;
			}
}

int Factorial(int n)
{
	if (n == 1) return 1;
	return n * Factorial(n - 1);
}