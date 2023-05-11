#include <bits/stdc++.h>
using namespace std;

int L;
string s;
long long ret;
#define M 1234567891;

int main()
{
	cin >> L >> s;

	long long powNum = 1;

	for (int i = 0; i < L; i++)
	{
		int alphabet = s[i] - 'a' + 1;	// 'a' == 1;
		ret = (ret + alphabet * powNum) % M;
		powNum = (powNum * 31) % M;
	}
	cout << ret;
}