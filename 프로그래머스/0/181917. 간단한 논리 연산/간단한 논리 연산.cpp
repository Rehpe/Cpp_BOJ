#include <string>
#include <vector>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) 
{
    bool x = x1 || x2;
    bool y = x3 || x4;
    return x && y;
}