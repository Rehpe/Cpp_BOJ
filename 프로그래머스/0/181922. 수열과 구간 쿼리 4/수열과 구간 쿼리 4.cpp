#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
 
    for(auto a : queries)
    {
        int s = a[0];
        int e = a[1];
        int k = a[2];
        
        for(int i = s; i <=e; i++)
        {
            if(i % k == 0)
                arr[i]+=1;
        }
    }
    
    return arr;
}