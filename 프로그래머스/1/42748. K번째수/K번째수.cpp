#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    
    for(auto command : commands)
    {
        int a = command[0];
        int b = command[1];
        int c = command[2];
        
        vector<int> v;
        
        for(int i = a-1; i <= b-1; i++)
        {
            v.push_back(array[i]);   
        }
        
        sort(v.begin(), v.end());
        answer.push_back(v[c-1]);
    }
    
    return answer;
}