#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			cnt++;
	}
	cnt++; // 마지막 남은 단어 count

	// words의 첫번째 요소나 마지막 요소가 blank일 경우 제거
	if (s[0] == ' ')
		cnt--;

	if (s[s.size() - 1] == ' ')
		cnt--;

	cout << cnt;
}
