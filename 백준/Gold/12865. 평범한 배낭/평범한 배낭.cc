#include <bits/stdc++.h>

using namespace std;

int n, k;
int W, V;

struct item
{
	int w;
	int v;
};

item items[104];
int dp[104][100004];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i].w >> items[i].v;
	}

	for (int j = 1; j <= k; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			// i번째 물건의 무게를 체크한다.
			int item_weight = items[i].w;
			int item_value = items[i].v;

			// i번째 물건의 무게가 현재 가방용량(j)보다 크다면, 넣지 않는다.
			if (item_weight > j)
				dp[i][j] = dp[i - 1][j];
			// i번째 물건의 무게가 현재 가방용량(j)보다 작거나 같다면,
			// 해당 물건을 넣지 않는 경우와 넣은 경우 중 큰 쪽을 저장한다.
			else
				dp[i][j] = max(dp[i - 1][j], item_value + dp[i - 1][j - item_weight]);
		}
	}

	cout << dp[n][k];

		
	return 0;
}