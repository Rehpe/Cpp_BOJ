#include <bits/stdc++.h>

using namespace std;

int n;
int maps[22][22];
bool selected[22];
int minSub = INT_MAX;

void calculate()
{
	// select된 idx는 team A, 안된 idx는 team B
	int Ascore = 0;
	int Bscore = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (selected[i] && selected[j])
				Ascore += maps[i][j];

			if (!selected[i] && !selected[j])
				Bscore += maps[i][j];
		}
	}

	minSub = min(minSub, abs(Ascore - Bscore));
}


void go(int cnt, int idx)
{
	if (cnt == n / 2)
	{
		calculate();
		return;
	}

	for (int i = idx; i <= n; i++)
	{
		selected[i] = 1;
		go(cnt + 1, i + 1);
		selected[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> maps[i][j];
		}
	}

	go(0, 1);

	cout << minSub;
	
	return 0;
}