#include <bits/stdc++.h>

using namespace std;

int n;
int dp[31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// 홀수개의 타일은 채울 수 없으므로 
	if (n % 2 != 0) cout << 0;
	else
	{
		dp[0] = 1;
		dp[2] = 3;

		for (int i = 4; i <= n; i+=2)
		{
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2)
			{
				dp[i] += dp[j] * 2;
			}
		}

		cout << dp[n];
	}

	
	return 0;
}