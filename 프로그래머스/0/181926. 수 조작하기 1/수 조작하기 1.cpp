#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) 
{
    for(int i = 0; i < control.size(); i++)
    {
        char p = control[i];
        if(p =='w')
            n+=1;
        else if(p =='s')
            n-=1;
        else if(p=='d')
            n+=10;
        else 
            n-=10;
    }
    
    return n;
}