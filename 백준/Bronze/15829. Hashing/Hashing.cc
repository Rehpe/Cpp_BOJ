#include <bits/stdc++.h>
using namespace std;

int L;
string s;
long long ret;

int main()
{
	cin >> L >> s;

	for (int i = 0; i < L; i++)
	{
		int alphabet = s[i] -'a' + 1;	// 'a' == 1;
		long long powNum = pow(31, i);
		ret += alphabet * powNum;
	}

	ret %= 1234567891;

	cout << ret;
}