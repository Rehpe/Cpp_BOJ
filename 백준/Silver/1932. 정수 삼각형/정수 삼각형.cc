#include <bits/stdc++.h>
using namespace std;

int n;
int tri[501][501];
int dp[501][501]; // dp[i][j] : i층 j번째 요소까지 고려했을 때까지의 최댓값
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}

	dp[1][1] = tri[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[n][i]);
	}

	cout << ans;
}
