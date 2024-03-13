#include <bits/stdc++.h>

using namespace std;

int N, M;
char campus[604][604];
int visited[604][604];
int cnt;
int starty, startx;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void dfs(int y, int x)
{
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx]) continue;
        if (campus[ny][nx] == 'X') continue;

        if (campus[ny][nx] == 'P') cnt++;
        dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> campus[i][j];

            if (campus[i][j] == 'I')
            {
                starty = i;
                startx = j;
            }
        }
    }

    visited[starty][startx] = 1;

    dfs(starty, startx);

    if (cnt)
        cout << cnt;
    else
        cout << "TT";

    return 0;
}