#include <bits/stdc++.h>
using namespace std;

int T;
string s;
int scr;
int Ocnt; //누적 정답 수

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> s;
		
		scr = 0;
		Ocnt = 0;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'O')	// 정답일 경우
			{
				Ocnt += 1;
				if (j == s.length() - 1)	// 마지막 문제일 때
				{
					scr += (1 + Ocnt) * Ocnt / 2;	// 등차수열의 합
					Ocnt = 0;						// 누적 정답 수 reset
				}
			}
			else			    // 오답일 경우
			{
				if (Ocnt == 0)
					continue;
				else
				{
					scr += (1 + Ocnt) * Ocnt / 2;	// 등차수열의 합
					Ocnt = 0;						// 누적 정답 수 reset
				}
			}
		}
		cout << scr;

		if (i == T - 1)
			return 0;
		else
			cout << '\n';
	}
}