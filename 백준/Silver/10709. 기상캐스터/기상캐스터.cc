#include <bits/stdc++.h>
using namespace std;

int H, W;
string s;
int a[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		cin >> s;
		for (int j = 0; j < W; j++)
		{
			if (s[j] == '.')
				a[i][j] = -1;
			else
				a[i][j] = 0;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			// 구름이면
			if (a[i][j] == 0)
			{
				int cnt = 1;

				// 다음 칸이 구름이 아니라면
				while (a[i][j + 1] == -1)
				{
					a[i][j + 1] = cnt++;	// 후위증감, 즉 기존 변수가 먼저 들어가고 이후에 증가
					j++;
				}
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}