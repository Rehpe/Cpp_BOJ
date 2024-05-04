#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int ladder[32][12];
int ans = INT_MAX;

bool check_ladder()
{
	for (int i = 1; i <= n; i++)	// 세로선
	{
		int col = i;

		for (int j = 1; j <= h; j++)	// 가로선
		{
			// col번째 세로줄에서 col+1 줄을 잇는 선이므로 col++;
			if (ladder[j][col])	
				col++;

			// col-1 번째 세로줄에서 col번째 줄을 잇는 선이므로 col--;
			else if (ladder[j][col - 1])	col--;
		}

		// 모든 가로선을 체크한 후 세로선이 그대로인지 체크
		if (col != i)
			return false;
	}

	return true;
}


void dfs(int maxDepth, int cnt)
{
	// 최대로 추가할 수 있는 만큼 사다리를 추가했다면
	if (cnt == maxDepth)
	{
		// 사다리 조건을 만족했다면
		if (check_ladder())
		{
			// depth가 작은 순으로 탐색하므로, 답을 찾는 순간 해당 답이 최소값이 됨
			// 그 이후의 경우의 수는 찾을 필요가 없으므로, 바로 답을 출력하고 종료
			cout << maxDepth;
			exit(0);
		}

		return;
	}

	for (int i = 1; i <= n; i++)	// 세로줄
	{
		for (int j = 1; j <= h; j++)	// 가로줄
		{
			if (ladder[j][i])	continue;	// 이미 해당 가로줄이 있다면 건너뜀
			if (ladder[j][i - 1] || ladder[j][i + 1]) continue;	// 바로 연속되는 가로줄이 있다면 건너뜀

			// i번째 세로줄 j번째 가로선을 추가
			ladder[j][i] = 1;

			dfs(maxDepth, cnt + 1);

			// 원상복구
			ladder[j][i] = 0;

			while (!ladder[j][i - 1] && !ladder[j][i + 1])	j++;
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	// 최대로 추가할 수 있는 사다리는 3개까지이므로, maxDepth에 대해 3까지 루프를 돌린다.
	for (int i = 0; i <= 3; i++)
	{
		dfs(i, 0);
	}

	// 3개 이하로 불가능한 경우 -1을 출력한다
	if (ans == INT_MAX)
		cout << -1;
	
	return 0;
}