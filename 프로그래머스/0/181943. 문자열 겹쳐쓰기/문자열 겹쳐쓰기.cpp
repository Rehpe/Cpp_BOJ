#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
    string answer = "";
    
    for(int i = 0; i < my_string.size(); i++)
    {
        if(i < s) 
            answer.push_back(my_string[i]);
        
        else
        {
            if(i-s < overwrite_string.size())
                answer.push_back(overwrite_string[i-s]);
            else
                answer.push_back(my_string[i]);
        }
    }
    return answer;
}