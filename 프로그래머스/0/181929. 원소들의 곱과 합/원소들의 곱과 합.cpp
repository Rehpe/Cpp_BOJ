#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) 
{
   int gob = num_list[0]; 
   for(int i = 1; i < num_list.size(); i++)
   {
       gob *= num_list[i];
   }
    
   int habzegob = accumulate(num_list.begin(), num_list.end(), 0);
   habzegob = pow(habzegob,2);
    
    if(gob < habzegob) return 1;
    else return 0;
}