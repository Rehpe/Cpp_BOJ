#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) 
{
   vector<int> result;

    for (const auto& query : queries)
    {
        int s = query[0];
        int e = query[1];
        int k = query[2];

        int minval = INT_MAX;
        for (int i = s; i <= e; ++i)
        {
            if (arr[i] > k)
                minval = min(minval,arr[i]);
        }
        
        if (minval != INT_MAX)
            result.push_back(minval);
        else
            result.push_back(-1);
    }
    
    return result;
}