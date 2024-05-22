#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[101][11];	// dp[i][j] = 끝 자리가 j인 i자리 계단수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// 0으로 시작하는 수는 계단수가 아니므로 제외
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)	// 자리수
	{
		for (int j = 0; j <= 9; j++) // 마지막 자리수
		{
			if (j == 0)
			{
				// 마지막 자리수가 0이라면, 앞에는 1로 끝나는 수만 올 수 있음
				dp[i][j] = dp[i - 1][j + 1]  % 1000000000;
			}
			else if (j == 9)
			{
				// 마지막 자리수가 9라면, 앞에는 8로 끝나는 수만 올 수 있음
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			}
			else
			{
				// 그 외의 수라면 j+1, j-1 로 끝나는 수가 올 수 있음
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
			}
		}
	}
	
	long long ans = 0;

	for (int i = 0; i <= 9; i++)
	{
		ans += dp[n][i] % 1000000000;
	}

	cout << ans % 1000000000;

	return 0;
}
