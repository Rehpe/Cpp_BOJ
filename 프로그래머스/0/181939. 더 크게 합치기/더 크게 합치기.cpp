#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    int answer = 0;
    string aa = to_string(a);
    string bb = to_string(b);
    
    string ab = aa+bb;
    string ba = bb+aa;
    
    if(ab.size() == ba.size())
    {
        if(ab>ba) answer = atoi(ab.c_str());
        else answer = atoi(ba.c_str());
    }
    else
    {
        if(ab.size() > ba.size())
            answer = atoi(ab.c_str());
        else
            answer = atoi(ba.c_str());
    }
    
    return answer;
}