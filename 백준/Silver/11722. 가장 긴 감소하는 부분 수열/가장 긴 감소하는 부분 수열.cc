#include <bits/stdc++.h>

using namespace std;

int arr_size;
int A[1001];
int dp[1001]; // i를 마지막 값으로 하는 가장 긴 감소하는 부분 수열의 길이
int ans;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> arr_size;

	for (int i = 1; i <= arr_size; i++)
	{
		cin >> A[i];

		int here = 0;

		for (int j = 1; j < i; j++)
		{
			/* 이전의 원소들과 현재의 원소(i번째 원소)를 비교한다.
			dp[i] = 1 ~ i - 1 (바로 직전 원소) 까지의 원소들 중, 
			i번째 원소보다 값이 큰 원소들의 dp값 중 가장 큰 값 + 1
			*/
			if (A[i] < A[j])
			{
				here = max(here, dp[j]);
			}
		}
		dp[i] = here + 1;
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}