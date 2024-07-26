#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) 
{
    vector<int> answer;
    
    for(int i = l; i <=r; i++)
    {
        if(i % 5 == 0)
        {
            string sint = to_string(i);
            bool flag = true;
            for(int j =0; j <sint.size(); j++)
            {
                if(sint[j] != '0' && sint[j]  !='5')
                {
                    flag = false;
                    break;
                }
            }
            if(flag) answer.push_back(i);
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}