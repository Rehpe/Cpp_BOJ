#include <bits/stdc++.h>

using namespace std;

int N;
int paper[129][129];
int bluecnt, whitecnt;
bool flag = true;


void cut(int x, int y, int size)
{
	flag = true;

	// 왼쪽상단 모서리의 색
	int color = paper[x][y];

	if (size == 1)
	{
		if (color == 1)
			bluecnt++;
		else
			whitecnt++;

		return;
	}

	// 전체 순회
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y+ size; j++)
		{
			if (color != paper[i][j])
			{
				// 왼쪽 상단 모서리의 색과 내부 색이 하나라도 다르다 -> 하나의 색종이가 되지 못함, 나눠야함
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag)
	{
		if (color == 1)
			bluecnt++;
		else
			whitecnt++;

		return;
	}

	else
	{
		// 해당 종이를 4등분함
		cut(x, y, size / 2);
		cut(x + size / 2, y, size / 2);
		cut(x, y + size / 2, size / 2);
		cut(x + size / 2, y + size / 2, size / 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			cin >> x;
			paper[i][j] = x;
		}
	}

	cut(0, 0, N);

	cout << whitecnt << '\n' << bluecnt;
};