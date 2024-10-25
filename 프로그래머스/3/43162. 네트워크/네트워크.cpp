#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201];


int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    for(int i = 0; i <n; i++)
    {
        if(visited[i]) continue;
        
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        
        while(!q.empty())
        {
            int x= q.front();
            q.pop();
            
            for(int j = 0; j < n; j++)
            {
                if(x ==j) continue;
                if(visited[j]) continue;
                if(computers[x][j]) // 연결된 경우
                {
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
        answer++;
    }
    
    return answer;
}