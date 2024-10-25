#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    pair<int, int> p;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
   for(int i = 0; i < priorities.size(); i++)
   {
       p = {i,priorities[i]};
       q.push(p);
       pq.push(priorities[i]);
   }
    
    int cnt = 1;
    while(!q.empty())
    {
        int index;
        int pri;
        tie(index, pri) = q.front();
        int maxp = pq.top();
        q.pop();
        
        if(pri!= maxp)
        {
            q.push({index, pri});
        }
        else
        {
            if(index == location)
                break;
            pq.pop();
            cnt++;
        }
    }
    
    return cnt;
}