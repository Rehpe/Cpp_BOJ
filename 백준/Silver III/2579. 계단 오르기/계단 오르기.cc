#include <bits/stdc++.h>
using namespace std;

int N;
int stair[301];
int dp[301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}

	// dp[i] = i번째 계단을 올랐을 때 얻을 수 있는 점수의 최댓값
	// 시작점에서 첫번째 계단 혹은 두번째 계단을 오를 수 있으므로 초기값 설정
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] =max( dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[N];

	return 0;
}