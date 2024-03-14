#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000004]; // i가 1이 되기 위한 최소연산 횟수
int pre[1000004]; // i가 1로 가기 위한 최적의 루트에서 이전 숫자

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;

        // i가 2의 배수이며, 2로 나누는 경우가 더 최솟값이라면
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }

        // i가 3의 배수이며, 3으로 나누는 경우가 더 최솟값이라면
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << dp[N] << '\n';

    // 경로 출력
    int cur = N;
    while (true)
    {
        cout << cur << ' ';

        if (cur == 1) break;
        cur = pre[cur];
    }

    return 0;
}