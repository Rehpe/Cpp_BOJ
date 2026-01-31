#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n)
{
    int pizzacnt = 0;
    while(true)
    {
        pizzacnt++;
        if((pizzacnt * slice) >= n)
            break;
    }
    
    return pizzacnt;
}