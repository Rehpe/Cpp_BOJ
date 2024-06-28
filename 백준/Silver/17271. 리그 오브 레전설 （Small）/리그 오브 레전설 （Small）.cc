#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int n, b;
int dp[10001];

long long go(int time)
{
	if (dp[time]) return dp[time];

	dp[time] = go(time - 1) % MOD;
	if (time >= b) dp[time] += dp[time - b] % MOD;

	return dp[time] % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> b;

	dp[0] = 1;

	cout << go(n);

	return 0;
}