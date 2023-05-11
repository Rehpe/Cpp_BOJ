#include <bits/stdc++.h>
using namespace std;

string s;
int alphabet[26];

int main()
{
	cin >> s;

	// -1로 배열 초기화
	memset(alphabet, -1, sizeof(alphabet));

	for (int i = 0; i < s.length(); i++)
	{
		int ascii = s[i] - 'a';

		if (alphabet[ascii] == -1)	// 요소가 -1일 경우, 즉 처음 등장할 때에만 기록
		{
			alphabet[ascii] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i];

		if (i == 25)
			return 0;
		else
			cout << " ";
	}
}