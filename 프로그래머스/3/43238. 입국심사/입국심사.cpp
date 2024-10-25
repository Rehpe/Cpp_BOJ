#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

long long solution(int n, vector<int> times) 
{
    long long answer = 0;
    long long s = times.size();   // 심사관 수
    sort(times.begin(), times.end());
    
    long long low = 1;
    long long high = (long long) times[0] * n; // 가장 긴 심사시간
    
    while(low <= high)
    {
        long long mid = (low + high) / 2;
        long long cnt = 0;   // 입국심사 받는 사람 수
        
        for(int i = 0; i < s; i++)
        {
            cnt += mid / times[i];
            if(cnt >= n) // 가능 : 주어진 사람 수를 초과하면 시간 줄이고 최적값찾기
            {
                break;
            }
        }
        
        if(cnt < n) // 실패: 시간부족, 시간 늘림
        {
            low = mid +1;
        }
        else // 성공: 최적화
        {
            high = mid -1;
            answer = mid;
        }
    }
    
    return answer;
}