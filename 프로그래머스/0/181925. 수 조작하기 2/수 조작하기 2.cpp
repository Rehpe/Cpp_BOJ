#include <string>
#include <vector>
#include <map>

using namespace std;
map<int, char> m = {{1,'w'}, {-1,'s'}, {10,'d'}, {-10,'a'}};

string solution(vector<int> numLog) 
{
    string answer = "";
    
    for(int i = 1; i < numLog.size(); i++)
    {
        int sub = numLog[i] - numLog[i-1];
        
        answer += m[sub];
    }
    
    return answer;
}