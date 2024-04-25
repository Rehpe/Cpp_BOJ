#include <bits/stdc++.h>

using namespace std;

int n;
int wine[10002];
int dp[10002];
int maxwine;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n];

	return 0;
}