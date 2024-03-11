#include <bits/stdc++.h>

using namespace std;

int N;
int dp[50001];

/* 점화식 유추해보기

dp[1] = 1
dp[2] = dp[1] + dp[1] = 2
dp[3] = dp[2] + dp[1] = 3
dp[4] = 1 (제곱수)
dp[5] = dp[4] + dp[1] = 2
dp[6] = dp[5] + dp[1] = dp[4] + dp[1] + dp[1] = 3
dp[7] = dp[6] + dp[1]  = dp[4] + dp[1] + dp[1] + dp[1] = 4
dp[8] = dp[4] + dp[4] = 2
...
dp[18] = dp[17] + dp[1] = 3 (X)
		 dp[9] + dp[9] = 2 (O)
		
즉, 기본적으로 dp[n] 은 dp[n-1] + dp[1](1) 의 값을 갖지만,
어떤 수 N에 대해서 제곱했을 때 N을 넘지 않는 수를 제곱해보며 구성했을 때 제곱수가 더 작은 경우를 찾는다.

*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 1; i <= N; i++)
	{
		//dp[i] = dp[i-1] + dp[1]이므로, dp[1] 을 1로 치환함
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++)
		{
			// 제곱했을 때 i를 넘지 않는 자연수 j를 제곱하며 제곱수를 찾아 작은 쪽으로 선택한다.
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];

	return 0;
};