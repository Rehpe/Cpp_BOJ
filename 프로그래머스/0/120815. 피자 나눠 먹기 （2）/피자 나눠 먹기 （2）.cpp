#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int pizzacnt = 0;
    
    while(true)
    {
        pizzacnt++;
        if((pizzacnt * 6) % n == 0)
            break;
    }
    
    return pizzacnt;
}