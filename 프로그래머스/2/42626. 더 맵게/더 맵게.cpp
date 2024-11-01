#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    for(int i =0;  i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.size() > 1)
    {
        int minhot = pq.top();
        pq.pop();
        if(minhot >= K)
        {
            break;
        }
        
        answer++;
        int newScoville = minhot + pq.top() * 2;
        pq.pop();
        pq.push(newScoville);
    }
    
    if(pq.size() == 1 && pq.top() < K) return -1;
    else return answer;
}