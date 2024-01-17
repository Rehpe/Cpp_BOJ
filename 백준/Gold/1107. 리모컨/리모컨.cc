#include <bits/stdc++.h>

using namespace std;

int N, brokencnt, brokenbtn;
bool isBroken[10] = { false, };
int ans;

bool check(int i)
{
	string num = to_string(i);

	for (int i = 0; i < num.size(); i++)
	{
		if (isBroken[num[i] - '0'])
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> brokencnt;

	for (int i = 0; i < brokencnt; i++)
	{
		cin >> brokenbtn;
		isBroken[brokenbtn] = true;
	}

	// 채널번호 N까지 +, - 하나만을 누르는 경우
	ans = abs(N - 100);

	for (int i = 0; i <= 1000000; i++)
	{
		// 0부터 1000000까지, 목표하는 채널번호 내에 고장난 번호가 있는지 체크
		if (check(i))
		{
			// 고장난 번호가 없다면 해당 번호를 누르고(번호 자리수만큼 +) 해당 번호에서 채널번호 N까지 +, - 눌러 도달하기
			int temp = abs(N - i) + to_string(i).size();
			ans = min(ans, temp);
		}
	}

	cout << ans;

	return 0;
}