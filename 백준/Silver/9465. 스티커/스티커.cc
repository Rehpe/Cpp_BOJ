#include <bits/stdc++.h>

using namespace std;

#define time aaa

int T;
int n;
int sticker[3][100002];
int dp[3][100002];	// dp[i][j] = i행 j열 스티커를 뗄 때의 최대 스티커점수
int ans;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> sticker[i][j];
			}
		}

		memset(dp, 0, sizeof(int));

		dp[1][1] = sticker[1][1];
		dp[2][1] = sticker[2][1];

		for (int i = 2; i <= n; i++)
		{
			dp[1][i] = sticker[1][i] + max(dp[2][i - 1], max(dp[1][i - 2], dp[2][i - 2]));
			dp[2][i] = sticker[2][i] + max(dp[1][i - 1], max(dp[1][i - 2], dp[2][i - 2]));
		}

		ans = max(dp[1][n], dp[2][n]);
		cout << ans << '\n';
	}


	return 0;
}