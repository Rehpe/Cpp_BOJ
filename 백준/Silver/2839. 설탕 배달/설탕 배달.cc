#include <bits/stdc++.h>
using namespace std;

int N;
int dp[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	dp[0] = dp[1] = dp[2] = dp[4] = 9999;
	dp[3] = dp[5] = 1;

	for (int i = 6; i < N + 1; i++)
	{
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}

	if (dp[N] >= 9999)
		cout << -1;
	else
		cout << dp[N];
}
