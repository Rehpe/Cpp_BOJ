#include <bits/stdc++.h>

using namespace std;

int n, m, k;	// n : 칸 크기, m : 나무 개수, k: k년 후
int yangbun[11][11];
int ground[11][11];
vector<int> growing_tree;
vector<int> dead_tree;
vector<pair<int, int>> five_multi_tree;
int new_tree[11][11];
priority_queue<int, vector<int>, greater<>> trees[11][11];
int dy[] = { -1, -1, 0, 1, 1,  1, 0, -1 };	// 위부터 시계방향
int dx[] = {  0,  1, 1, 1, 0, -1, -1,-1 };

int living_tree;

void spring()
{
	// 칸에서 어린 나무부터 자기 나이만큼의 양분을 먹고 나이가 1 증가함
	// 양분을 먹을 수 없는 나무는 죽는다
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 한 칸의 모든 나무에 대해 어린 순으로 양분 먹고 자라기 / 죽기
			while (!trees[i][j].empty())
			{
				int tree_year = trees[i][j].top();
				trees[i][j].pop();

				if (ground[i][j] >= tree_year)
				{
					ground[i][j] -= tree_year;
					tree_year++;
					growing_tree.push_back(tree_year);

					// 여기서 나이가 5의 배수인 나무 개수 저장
					if(tree_year % 5 == 0)
						five_multi_tree.push_back({i,j});
				}
				else
					dead_tree.push_back(tree_year);
			}

			// 모든 나무에 대해 처리가 끝났다면, 다시 pq에 살아남은 나무를 push
			for (int tree : growing_tree)
			{
				trees[i][j].push(tree);
			}

			// 죽은 나무 처리-> 죽은 나무가 해당 칸에 나이/2 만큼의 양분으로 추가됨
			for (int dead_tree_year : dead_tree)
			{
				int new_yangbun = dead_tree_year / 2;
				ground[i][j] += new_yangbun;
			}

			growing_tree.clear();
			dead_tree.clear();

			// 양분도 지금 줘버림
			ground[i][j] += yangbun[i][j];
		}
	}
}

void autumn()
{
	// 나이가 5의 배수인 나무가 인접 8칸에 번식함
	for (auto coord : five_multi_tree)
	{
		int y = coord.first;
		int x = coord.second;

		// 8방향 번식
		for (int dir = 0; dir < 8; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny <1 || nx <1 || ny >n || nx > n) continue;

			// 해당 칸에 나이가 1인 나무 추가
			trees[ny][nx].push(1);
		}
	}

	five_multi_tree.clear();
}

void winter()
{
	//living_tree = 0; 

	// 땅에 양분 추가
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ground[i][j] += yangbun[i][j];

			// 한 칸의 모든 나무 세기
			//living_tree += trees[i][j].size();
		}
	}
}

int counting_trees()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 한 칸의 모든 나무 세기
			living_tree += trees[i][j].size();
		}
	}

	return living_tree;
}


void growing_trees(int year)
{
	while (year--)
	{
		spring();
		//summer();
		autumn();
		//winter();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> yangbun[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int y, x, years;
		cin >> y >> x >> years;
		trees[y][x].push(years);
	}

	// 첫 해에 양분은 모든 땅에 5만큼 들어있다
	fill(&ground[0][0], &ground[0][0] + 11 * 11, 5);

	growing_trees(k);
	cout << counting_trees();
	//cout << living_tree;

	return 0;
}