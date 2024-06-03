#include <bits/stdc++.h>

using namespace std;

double Apercent, Bpercent;
bool isPrime[21];
double dp[20][20][20];	// dp[idx][a][b] : idx번째 경기에 a대b 인 상황에서, 경기 종료후 소수득점이 나오는 경우의 수

double go(int idx, int a, int b)
{
	// 모든 경기가 끝났다면
	if (idx == 18)
	{
		// a득점 b득점 둘 중 하나라도 소수라면 +1
		if (isPrime[a] || isPrime[b]) return 1.0;
		else  return 0.0;
	}

	// 실수형 연산은 == 처리가 어려우므로, 초기 dp테이블을 -1(절대로 나오지 않을 수)로 설정 후
	// 크기 대소비교로 갱신 여부를 파악한다.

	if (dp[idx][a][b] > -0.5) return dp[idx][a][b];	// 갱신했던 값이 있다면 그 값을 반환

	dp[idx][a][b] = 0.0;

	dp[idx][a][b] += go(idx + 1, a + 1, b + 1) * Apercent * Bpercent; // a,b 모두 골 넣을 확률
	dp[idx][a][b] += go(idx + 1, a, b) * (1 - Apercent) * (1-Bpercent); // a,b 모두 골 못 넣을 확률
	dp[idx][a][b] += go(idx + 1, a + 1, b) * Apercent * (1-Bpercent); // a만 골 넣을 확률
	dp[idx][a][b] += go(idx + 1, a, b + 1) * (1-Apercent) * Bpercent; // b만 골 넣을 확률
	
	return dp[idx][a][b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> Apercent >> Bpercent;

	// 퍼센트를 구하기 위해 100으로 나눔
	Apercent /= 100;
	Bpercent /= 100;

	// 에라토스테네스의 체로 18(90분 / 5분)까지의 소수를 구함
	fill(isPrime, isPrime + 20,  1);
	isPrime[0] = 0; isPrime[1] = 0;
	for (int i = 2; i <= sqrt(20) + 1; i++)
	{
		if (isPrime[i] == 0) continue;

		for (int j = i*i; j <= 20; j +=i)
		{
			isPrime[j] = 0;
		}
	}

	// dp테이블 -1로 초기화
	memset(dp, -1, sizeof(dp));

	// 0번째 idx부터, 0-0 상황에서부터 함수 시작
	cout << go(0, 0, 0);

	return 0;
}
