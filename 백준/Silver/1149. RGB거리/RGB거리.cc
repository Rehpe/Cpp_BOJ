#include <bits/stdc++.h>

using namespace std;

int N; // 집의 수
int R[1001], G[1001], B[1001]; // N번째 집을 각각 R, G, B 색으로 칠했을 때의 비용
int dp[1001][3]; // N번째 집이 R/G/B 색일 때의 최소비용


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> R[i] >> G[i] >> B[i];
    }
   
    dp[0][0] = R[0];
    dp[0][1] = G[0];
    dp[0][2] = B[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
    }

    cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);

}