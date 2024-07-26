#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int c, int d) 
{
    map<int, int> dice;
    dice[a]++;
    dice[b]++;
    dice[c]++;
    dice[d]++;
      
    vector<int> values;
    for (auto pair : dice) 
    {
        values.push_back(pair.first);
    }

    if(values.size() == 1)
    {
        return 1111 * values[0];
    }
    else if(values.size() == 2)
    {
         // 세 숫자 동일, 다른 한 숫자
        if(dice[values[0]] == 3 || dice[values[1]] == 3)
        {
            if(dice[values[0]] == 3)
                return pow((10 * values[0]) + values[1],2);
            else
                return pow((10 * values[1]) + values[0],2);
        }
        else    // 두 숫자씩 같음
        {
            return (values[0] + values[1]) * abs(values[0] - values[1]);  
        }
    }
    else if(values.size() == 3) // 두 숫자 동일, 다른 두 숫자
    {
        int temp = 1;
        for(int i = 0; i <3; i++)
        {
            if(dice[values[i]] == 1)
            {
                temp *= values[i];
            }
        }
        return temp;
    }
    else
    {
        return *min_element(values.begin(), values.end());
    }
}