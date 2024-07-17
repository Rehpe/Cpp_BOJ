#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    string str;
    cin >> str;
    
    for(int i =0; i < str.size(); i++)
    {
        if( 'A' <= str[i] && str[i] <='Z')
        {
            str[i] = tolower(str[i]);
        }
        else
            str[i] = toupper(str[i]);
    }
    
    cout << str;
    return 0;
}