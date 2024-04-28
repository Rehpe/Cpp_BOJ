#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[101];
int dp[10001];	// dp[i] = i원을 만들기 위해 필요한 최소 동전 개수
int mincoin = INT_MAX;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];

		// 입력받은 동전의 가치가 k라면, k원을 만들기 위해 필요한 최소 동전 개수는 1개이다
		// dp배열 범위를 넘어가지 않기 위해, 범위 내에서만 기록
		if(coin[i] <= 10000)
			dp[coin[i]] = 1;
	}

	// coin 배열을 오름차순으로 정렬
	sort(coin, coin + n);

	for (int i = 1; i <= k; i++)
	{
		if (dp[i] == 1)	continue;	// 1개가 최소값이므로 이 경우 넘어감

		// 최소값을 구하기 위해 임시로 dp[i] = INT_MAX값 부여
		dp[i] = INT_MAX;

		for (int j = 0; j < n; j++)
		{
			// 현재 탐색하는 i보다 작은 수 중 가장 큰 값부터 검색한다.
			if (coin[j] > i)	continue;

			// 불가능한 값이라면 continue;
			if (dp[i - coin[j]] == -1) continue;

			else
			{
				int temp;
				temp = 1 + dp[i - coin[j]];

				dp[i] = min(temp, dp[i]);
			}
		}

		// 위 식에서 처리되지 않은 값들은 불가능한 값이므로 -1로 기록
		if (dp[i] == INT_MAX) dp[i] = -1;
	}

	cout << dp[k];
}
