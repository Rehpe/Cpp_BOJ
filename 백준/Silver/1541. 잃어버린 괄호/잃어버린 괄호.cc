#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

string str;
string number;
bool minusflag;
int ans;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	for (int i = 0; i <= str.size(); i++)
	{
		// 기호거나 식의 끝이라면
		if (str[i] == '-' || str[i] == '+' || i == str.size())
		{
			// 1. minus flag 가 있다면 저장된 숫자를 뺀다('-'가 있었다면)
			if (minusflag)
			{
				ans -= stoi(number);
			}

			// 2. minus flag가 없다면 저장된 숫자를 더한다
			else
				ans += stoi(number);

			// 숫자 리셋
			number = "";

			// minus를 만나면 minus flag를 켜준다
			if (str[i] == '-')
				minusflag = true;
		}

		// 숫자라면 string number에 숫자 기록
		else
			number += str[i];
	}

	cout <<  ans;
	return 0;
};