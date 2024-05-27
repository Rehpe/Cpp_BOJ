#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAX 102
using namespace std;

int board[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int num = 1,N;
queue<pair<int, int>> q;
vector<pair<int, int>> vp;

int bfs(int x, int y) {
	int dist[MAX][MAX] = { 0, };
	int mindist = 1e8;
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cur.first + dx[k];
			int ny = cur.second + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (dist[nx][ny] != 0) continue;
			if (board[nx][ny] == board[x][y]) continue;
			if (board[nx][ny] != board[x][y] && board[nx][ny] != 0) {
				mindist = min(mindist, dist[cur.first][cur.second]);
				continue;
			}
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	return mindist;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && check[i][j] == false) {
				q.push({ i,j });
				check[i][j] = 1;
				board[i][j] = num;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int k= 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (check[nx][ny]) continue;
						if (board[nx][ny] == 0) {
							vp.push_back({ cur.first,cur.second });
							continue;
						}
						check[nx][ny] = 1;
						board[nx][ny] = num;
						q.push({ nx,ny });
					}
				}
				num++;
			}
		}
	}
    sort(vp.begin(),vp.end());
	vp.erase(unique(vp.begin(), vp.end()), vp.end());
	int resultdist = 1e9;
	for (int i = 0; i < vp.size(); i++) {
		resultdist = min(resultdist,bfs(vp[i].first, vp[i].second));
	}
	cout << resultdist;
}