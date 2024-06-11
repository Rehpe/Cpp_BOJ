#include <bits/stdc++.h>

using namespace std;

int n, m;	// n:건너는 횟수 m: 각 줄의 칸
bool maps[1001][1001];
long long dp[1001][1001];		// dp[i][j] = i번째 걸음에서 m번째 칸에 위치할 때 끝까지 가는 경우의수


int go(int num, int kan)
{
	if (maps[num][kan] == 0)
	{
		dp[num][kan] = 0;
		return 0;
	}

	if (num == n - 1) return 1;

	if (dp[num][kan] != -1) return dp[num][kan];

	dp[num][kan] = 0;

	for (int available_kan : {kan - 1, kan, kan + 1})
	{
		// 맵 범위 밖이라면 스킵
		if (available_kan < 0 || available_kan >= m)	continue;

		dp[num][kan] = (dp[num][kan] + go(num + 1, available_kan)) % 1000000007;
	}

	return dp[num][kan] % 1000000007;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));

	long long ans = 0;

	for (int i = 0; i < m; i++)
	{
		ans += (go(0, i) % 1000000007);
	}

	cout << ans % 1000000007;

	return 0;
}