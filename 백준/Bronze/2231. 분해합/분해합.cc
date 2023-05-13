#include <bits/stdc++.h>
using namespace std;

int N;
int sum;

int cons(int n)
{
	string s = to_string(n);
	int numlength = s.length();		// 자리수

	// 각 자리수에 들어갈 수 있는 최대 숫자는 9
	// 따라서 생성자의 최소값은 분해합 - 자리수*9 이다.

	for (int i = n - numlength*9; i < n; i++)
	{
		string num = to_string(i);

		sum += i;
		for (char c : num)
		{
			sum += c - '0';
		}

		if (sum == n)
			return i;
		else
			sum = 0;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << cons(N);
}