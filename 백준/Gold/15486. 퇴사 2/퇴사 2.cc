#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> schedule[1500002];
int dp[1500002];		// dp[i] : i일까지 얻을 수 있는 최대 수익
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int time, pay;
		cin >> time >> pay;
		schedule[i] = { time, pay };
	}

	dp[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		int i_time = schedule[i].first;
		int i_pay = schedule[i].second;

		if(dp[i] < dp[i-1])
			dp[i] = dp[i - 1];

		// i일의 총 상담시간이 n+1일을 넘어가면 상담 불가능
		if (i + i_time > n + 1)
		{	
			continue;
		}
		else
		{
			dp[i + i_time] = max(dp[i] + i_pay, dp[i+i_time]);
			ans = max(ans, dp[i + i_time]);
		}
	}

	cout << ans;

	return 0;
}