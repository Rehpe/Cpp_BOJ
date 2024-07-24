#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) 
{
    int last = num_list.size() - 1;
    
    if(num_list[last] > num_list[last-1])
        num_list.push_back(num_list[last] - num_list[last-1]);
    else
        num_list.push_back(num_list[last] * 2);
    
    return num_list;
}