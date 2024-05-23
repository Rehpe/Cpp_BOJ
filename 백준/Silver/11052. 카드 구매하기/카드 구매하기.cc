#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int dp[1001];	// dp[i] = i개 카드를 모으기 위해 지불해야하는 최대값

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		int maximum = 0;
		for (int j = i / 2; j >= 1; j--)
		{
			maximum = max(maximum, dp[j] + dp[i - j]);
		}
		dp[i] = max(arr[i], maximum);
	}

	cout << dp[n];

	return 0;
}