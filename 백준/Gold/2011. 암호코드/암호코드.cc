#include <bits/stdc++.h>

using namespace std;

string num;
int numsize;
int dp[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> num;

	numsize = num.size();

	if (num[0] == '0')
	{
		cout << 0;
		return 0;
	}
	else
	{
		dp[1] = 1;

		int doublenum = int(num[0] - '0') * 10 + int(num[1] - '0');

		if (num[1] == '0')
		{
			if (doublenum > 26)
			{
				cout << 0;
				return 0;
			}

			dp[2] = 1;
		}

		else if (1 <= doublenum && doublenum <= 26) dp[2] = 2;
		else
		{
			dp[2] = 1;
		}
	}

	for (int i = 2; i < numsize; i++)
	{
		if (num[i] == '0')
		{
			if (num[i - 1] == '0')
			{
				// 00은 불가능한 암호
				cout << 0;
				return 0;
			}
			else if(num[i-1] == '1' || num[i - 1] == '2')
			{
				// 10, 20은 가능한 암호
				// 분해할 수 없으므로 
				dp[i+1] = dp[i - 1] % 1000000;
			}
			else
			{
				// 30부터는 불가능한 암호
				cout << 0;
				return 0;
			}
		}
		else
		{
			if (num[i - 1] == '0')
			{
				//01, 02.. 는 분해할 수 없다
				dp[i+1] = dp[i] % 1000000;
			}
			else
			{
				// 두 자리수가 유효할 때(1~26 사이)
				int doublenum = int(num[i - 1] - '0') * 10 + int(num[i] - '0');
				if (1 <= doublenum && doublenum <= 26)
				{
					dp[i+1] = dp[i] % 1000000 + dp[i - 1] % 1000000;
				}
				// 두 자리수가 유효하지 않을 때
				else
				{
					dp[i+1] = dp[i] % 1000000;
				}
			}
		}
	}

	cout << dp[numsize] % 1000000;

	return 0;
}


