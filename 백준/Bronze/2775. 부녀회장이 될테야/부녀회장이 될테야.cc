//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;

int T;
int k, n;
int dp[15][15];

int go(int k, int n)
{
	if (k == 0)
	{
		dp[k][n] = n;
		return dp[k][n];
	}
	if (n == 1)
	{
		dp[k][n] = 1;
		return dp[k][n];
	}

	if (dp[k][n] != -1)
		return dp[k][n];

	else
		dp[k][n] = go(k-1, n) + go(k, n-1);

	return dp[k][n];

}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;

		memset(dp, -1, sizeof(dp));

		cout << go(k, n);

		if (i == T - 1)
			return 0;
		else
			cout << '\n';
	}
};