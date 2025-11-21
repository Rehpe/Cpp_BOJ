#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    // 1. 근무 태도 점수가 높은 순부터 정렬한다
    if(a[0] != b[0])
        return a[0] > b[0];
    // 2. 근무 태도 점수가 같다면 동료 평가 점수는 낮은 순부터 정렬한다.
    return a[1] < b[1];
}

int solution(vector<vector<int>> scores) 
{
    // 완호의 점수를 변수로 따로 저장
    int myWork = scores[0][0];
    int myPeer = scores[0][1];
    int mySum = myWork + myPeer;
    
    // 1등부터 시작
    int rank = 1;
    
    sort(scores.begin(), scores.end(), compare);
    
    int maxPeer = -1;
    
    for(int i = 0; i < scores.size(); i++)
    {
        int workScore = scores[i][0];
        int peerScore = scores[i][1];
        
        // 1. 현재까지의 maxPeer값보다 peerScore가 낮으면 탈락
        if(maxPeer > peerScore)
        {
            // 완호와 같다면 탈락 -> -1 리턴 후 종료
            if(workScore == myWork && peerScore == myPeer)
                return -1;
            
            continue;
        }
        
        // 2. 탈락자가 아니라면
        maxPeer = max(maxPeer, peerScore); // maxPeer 갱신
        
        // 점수의 합이 완호보다 크다면 완호의 등수+1(뒤로 밀림)
        if(workScore + peerScore > mySum)
            rank++;
    }
    
    return rank;
}