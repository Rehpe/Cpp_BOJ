#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = nums.size() / 2;
    unordered_set<int> hashset;
    
    for(int num : nums)
    {
        hashset.insert(num);
    }
    
    int maxkind = hashset.size();
    
    answer = min(cnt, maxkind);

    return answer;
}