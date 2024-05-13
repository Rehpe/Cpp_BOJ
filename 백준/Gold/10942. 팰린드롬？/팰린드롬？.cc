#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[2002];
int dp[2002][2002];	// dp[i][j] = i부터 j까지의 수가 팰린드롬인지 여부
pair<int, int> question[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		question[i] = {s, e};
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;
		if (i != 1 && arr[i - 1] == arr[i])
		{
				dp[i-1][i] = 1;
		}
	}

	// 길이가 2 이상인 경우
	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 1; j + i <= n; j++)
		{
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1] == 1)
				dp[j][j + i] = 1;
		}
	}


	for (int i = 0; i < m; i++)
	{
		int s, e;
		tie(s, e) = question[i];

		cout << dp[s][e] <<'\n';
	}

	return 0;
}