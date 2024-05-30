#include <bits/stdc++.h>

using namespace std;

int n;
int health[21];
int joy[21];
int dp[101];	// dp[i] : 체력이 i일 때 얻을 수 있는 최대 기쁨

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> health[i];
	}

	for (int j = 0; j < n; j++)
	{
		cin >> joy[j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j > health[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - health[i]] + joy[i]);
		}
	}

	cout << dp[100];

	return 0;
}
