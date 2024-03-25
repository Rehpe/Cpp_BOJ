#include <bits/stdc++.h>

using namespace std;

#define time aaa

int t, w;
int droporder[1002];
int dp[3][31][1002];
int ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t >> w;

	for (int i = 1; i <= t; i++)
	{
		cin >> droporder[i];
	}

	memset(dp, -1, sizeof(dp));


	dp[1][w][0] = 0;

	for (int time = 0; time < t; time++)
	{
		for (int cnt = 0; cnt <= w; cnt++)
		{
			for (int pos = 1; pos <= 2; pos++)
			{
				if (dp[pos][cnt][time] >= 0)
				{
					int nextpos = droporder[time + 1];


					// 다음 초에 자두가 서있는 곳에 자두가 떨어질 경우
					if (pos == nextpos)
					{
						dp[pos][cnt][time + 1] = dp[pos][cnt][time] + 1;
					}
					// 다음 초에 자두가 서있지 않은 곳에 자두가 떨어질 경우
					else
					{
						// 움직일 수 있는 횟수가 남아있는 경우 - 움직여서 자두를 줍는 경우
						if (cnt > 0)
						{
							dp[nextpos][cnt - 1][time + 1] =
								max(dp[nextpos][cnt - 1][time + 1],
									dp[pos][cnt][time] + 1);
						}
						// 움직이지 않는 경우
						dp[pos][cnt][time + 1] = dp[pos][cnt][time];
					}
				}
			}
		}
	}

	// 끝나는 시간의 모든 경우에 대해 최대값을 출력
	for (int pos = 1; pos <= 2; pos++)
	{
		for (int cnt = 0; cnt <= w; cnt++)
		{
			ret = max(ret, dp[pos][cnt][t]);
		}
	}
	
	cout << ret;

	return 0;
}