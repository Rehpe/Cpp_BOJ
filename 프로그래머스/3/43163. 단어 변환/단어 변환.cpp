#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isHit(string a, string b)
{
    int nothit = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) nothit++;
        if(nothit > 1) return false;
    }
    return true;
}


int solution(string begin, string target, vector<string> words) 
{
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    
    visited.insert(begin);
    q.push({begin, 0});
    
    while(!q.empty())
    {
        string curword = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(curword == target) return cnt;
        
        for(int i=0; i < words.size(); i++)
        {
            if(isHit(curword, words[i]))
            {
                // 방문하지 않았을 때에만
                if(visited.find(words[i]) == visited.end())
                   {
                        visited.insert(words[i]);
                        q.push({words[i], cnt+1});
                   }
            }
        }
    }

    return 0;
}