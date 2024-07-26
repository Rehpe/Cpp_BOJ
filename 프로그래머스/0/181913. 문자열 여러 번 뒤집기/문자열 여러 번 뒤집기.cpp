#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) 
{
    string answer = "";
    
    for(int i =0; i < queries.size(); i++)
    {
        int s = queries[i][0];
        int e = queries[i][1];
        
        string temp = "";

        for(int i = e; i >= s; i--)
        {
            temp += my_string[i];
        }
        my_string.replace(s,temp.length(), temp);
    }
    return my_string;
}