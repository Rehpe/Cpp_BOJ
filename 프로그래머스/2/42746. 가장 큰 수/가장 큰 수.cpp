#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b+a;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    
    vector<string> strnums;
    for(auto a : numbers)
    {
        strnums.push_back(to_string(a));
    }
    
    sort(strnums.begin(), strnums.end(), compare);
    
    for(auto a: strnums)
    {
        answer += a;
    }
    
    if(answer[0] == '0') return "0";
    else return answer;
}