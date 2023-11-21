#include <bits/stdc++.h>

using namespace std;

int N; 
int L, R;
int A[51][51];
int visited[51][51];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
vector<pair<int, int>> unions;
vector < vector<pair<int, int>>> uniongroup;
int daycnt;
int population;
int movecnt;

void bfs(int y, int x)
{	
	visited[y][x] = 1;

	unions.push_back({ y, x });

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		if (visited[ny][nx]) continue;
		if (abs(A[ny][nx] - A[y][x]) < L || abs(A[ny][nx] - A[y][x]) > R) continue;

		bfs(ny, nx);
	}

	return;
}

int main()
{
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	while (true)
	{
		memset(visited, 0, sizeof(visited));
		uniongroup.clear();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j]) continue;

				unions.clear();
				bfs(i, j);

				if (unions.size() > 1)
					uniongroup.push_back(unions);
			}
		}

		if (uniongroup.size())
		{
			for (auto unioncountrys : uniongroup)
			{
				for (int i = 0; i < unioncountrys.size(); i++)
				{
					population += A[unioncountrys[i].first][unioncountrys[i].second];
				}
				population /= (int)unioncountrys.size();

				for (int i = 0; i < unioncountrys.size(); i++)
				{
					A[unioncountrys[i].first][unioncountrys[i].second] = population;
				}
				population = 0;
			}
		}

		if (uniongroup.size()>=1)
			daycnt++;
		else
			break;
	}
	
	cout << daycnt;

	return 0;
}
