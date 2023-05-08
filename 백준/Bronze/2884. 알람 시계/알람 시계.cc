#include <bits/stdc++.h>
using namespace std;

int H, M;

int main()
{
	cin >> H >> M;

	// M에서 45을 뺀 수가 음수일 경우 -> 60분법으로 계산 후 H에서 1 빼기
	if (M - 45 < 0)
	{
		M = 60 - (45 - M);
		H -= 1;
	}
	else
	{
		M -= 45;
	}

	if (H < 0)	// 시간이 0보다 작을 경우 24시에서 1 빼기
	{
		H = 23;
	}
	else
	{
		H;
	}

	cout << H << " " << M;
}
