#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int dp[5][5][100001];
int arrsize;

//from에서 to까지 발을 움직일 때 들어가는 힘 반환
int calc_cost(int from, int to)
{
	// 0에서 움직이는 경우 2
	if (from == 0) return 2;
	// 같은 곳을 다시 누르는 경우 1
	if (from == to) return 1;
	// 위-아래 혹은 좌-우 처럼 반대일 경우 4
	if (abs(from - to) == 2) return 4;

	// 그 외 3
	return 3;
}


int go(int left, int right, int idx)	// 왼발, 오른발, 현재 인덱스
{
	if (idx == arrsize) return 0;

	// idx번째의 입력까지 받았을 때 왼발이 left 위치, 오른발이 right 위치에 있을 때 드는 최소힘
	if (dp[left][right][idx] != -1) return dp[left][right][idx];

	// 오른발, 왼발 중 힘을 더 적게 들이는 쪽으로 움직인다
	int left_move_cost = go(v[idx], right, idx + 1) + calc_cost(left, v[idx]);
	int right_move_cost = go(left, v[idx], idx + 1) + calc_cost(right, v[idx]);
	dp[left][right][idx] = min(left_move_cost, right_move_cost);

	return dp[left][right][idx];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		v.push_back(x);
	}

	// -1로 dp 초기화
	memset(dp, -1, sizeof(dp));
	arrsize = v.size();

	cout << go(0, 0, 0);	// 두 발이 0에 위치하고, 0번째 순서의 ddr에서 시작

	return 0;
}