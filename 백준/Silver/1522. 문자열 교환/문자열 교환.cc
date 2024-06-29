#include <bits/stdc++.h>

using namespace std;

string s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	int a = 0;
	int ans = s.size();

	for (auto c : s) if (c == 'a') a++;

	for (int i = 0; i < s.size(); i++)
	{
		int cnt = a;
		int temp = 0;	//바꿔야 할 b의 개수
		for (int j = i; j < i + s.size(); j++)
		{
			if (cnt == 0) break;
			if (s[j % s.size()] == 'b')
			{
				temp++;
				cnt--;
			}
			else cnt--;
		}
		ans = min(ans, temp);
	}
	cout << ans;

	return 0;
}