#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    string odd = ""; //홀
    string even =""; //짝
    
    for(int i = 0; i < num_list.size(); i++)
    {
        if(num_list[i] & 1)
            odd += to_string(num_list[i]);
        else
            even += to_string(num_list[i]);
    }
    
    int iodd = atoi(odd.c_str());
    int ieven = atoi(even.c_str());
    
    return iodd+ieven;
}