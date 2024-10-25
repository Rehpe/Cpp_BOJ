#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 합이 0이면 아무것도 선택하지 않는 경우 하나
    dp[0] = 1;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = i; j <= 10000; j++)
        {
            dp[j] += dp[j - i];
        }
    }

    
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }

    return 0;
}