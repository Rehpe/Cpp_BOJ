#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) 
{
    int answer = 0;
    sort(array.begin(), array.end());
    int half = array.size() / 2;
    
    answer = array[half];
    return answer;
}