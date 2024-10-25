#include <string>
#include <vector>

using namespace std;

int visited[2][21];
int s;
int t;
int answer;
vector<int> nums;

void go(int idx, int sum)
{
    if(idx == s)
    {
        if(sum == t) 
        {
            answer++;
            return;
        }
        return;
    }
    // +의 경우
    go(idx+1, sum + nums[idx]);
    
    // -의 경우
    go(idx+1, sum - nums[idx]);
}


int solution(vector<int> numbers, int target) 
{
    s = numbers.size();
    t = target;
     
    nums = numbers;
  
    go(0, 0);
    
    return answer;
}