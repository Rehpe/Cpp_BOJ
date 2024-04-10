#include <bits/stdc++.h>
using namespace std;

#define y1 aaa


int n, m;
int x1, x2, y1, y2;
int maps[1025][1025];
int dp[1025][1025];
int sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> maps[i][j];

			if (i == 1 && j == 1) dp[i][j] = maps[i][j];
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + maps[i][j];
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];

		cout << sum << '\n';
	}
}
