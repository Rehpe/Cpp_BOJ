#include<vector>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
int y, x;
int visited[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    
    visited[0][0] = 1;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(q.size())
    {
        tie(y, x) = q.front();
        q.pop();
    
        for(int i = 0; i <4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0 || nx<0 || ny>n-1 || nx >m-1) continue;
            if(maps[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    if(visited[n-1][m-1]) return visited[n-1][m-1];
    else return -1;
}