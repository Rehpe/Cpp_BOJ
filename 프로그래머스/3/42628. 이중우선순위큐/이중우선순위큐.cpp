#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) 
{
    vector<int> answer;
    
    priority_queue<int> Maxpq;
    priority_queue<int, vector<int>, greater<>> Minpq;
    unordered_map<int, int> um;
    
    for(int i =0; i < operations.size(); i++)
    {
        if(operations[i][0] == 'I')
        {
            int number = 0;
            if(operations[i][2] == '-')
            {
                string num = "";
                for(int j =3; j < operations[i].size(); j++)
                {
                    num += operations[i][j];
                }
                number = stoi(num) * -1;
            }
            else
            {
                string num = "";
                for(int j =2; j < operations[i].size(); j++)
                {
                    num += operations[i][j];
                }
                number = stoi(num);
            }
            Maxpq.push(number);
            Minpq.push(number);
            um[number]++;
        }
        else if(operations[i] == "D 1")  // 최댓값 삭제
        {
           if(Maxpq.empty()) continue;
            
            while(!Maxpq.empty() && um[Maxpq.top()] <=0)
            {
                Maxpq.pop();
            }
            if(!Maxpq.empty()){
            int Maxv = Maxpq.top();
            um[Maxv]--;
            Maxpq.pop();}
        }
        else // 최솟값 삭제
        {  
            if(Minpq.empty()) continue;
         
            while(!Minpq.empty() && um[Minpq.top()] <=0)
            {
                Minpq.pop();
            }
            if(!Minpq.empty()){
            int Minv = Minpq.top();
            um[Minv]--;
            Minpq.pop();}
        }
    }
    
    while (!Maxpq.empty() && um[Maxpq.top()] == 0) 
    {
        Maxpq.pop();
    }
    while (!Minpq.empty() && um[Minpq.top()] == 0) 
    {
        Minpq.pop();
    }
    
    
    if(Maxpq.empty())
    {
       answer = {0,0};
    }
    else
    {
        answer = { Maxpq.top(), Minpq.top()};
    }
    
    return answer;
}