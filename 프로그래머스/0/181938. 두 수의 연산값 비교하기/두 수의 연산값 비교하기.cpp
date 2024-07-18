#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    int answer = 0;
    string aa = to_string(a);
    string bb = to_string(b);
    
    string sab = aa+bb;
    int ab = atoi(sab.c_str());
    
    int ab2 = 2 * a* b;
    
    if(ab > ab2) answer = ab;
    else answer = ab2;
    
    return answer;
}