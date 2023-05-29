#include <bits/stdc++.h>
using namespace std;

int N;
int dp[5001];

int go(int x)	// x 킬로그램의 설탕을 구성하는 최소 봉지수
{
	if (x == 1 || x == 2 || x == 4)	// 3,5키로 봉지로 구성할 수 없는 숫자의 경우 최대수 반환
		return 99999;

	else if (x == 3 || x == 5)	// 3, 5키로 봉지의 경우 1이 최소값
		return 1;
	
	else if (dp[x] != 0)	// x에 대한 최소 봉지 수가 기록되어있다면 해당 값 반환
		return dp[x];
	
	else
	{
		// x kg를 구성하는 봉지의 최소 개수: 
		// x-3 kg를 구성하는 최소수 +1 혹은 x-5 kg를 구성하는 최소수 +1 중 작은 쪽
		dp[x] = min(go(x - 3) + 1, go(x - 5) + 1);
		return dp[x];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	int ret = go(N);

	if (ret >= 9999)
		cout << -1;
	else
		cout << ret;
}
