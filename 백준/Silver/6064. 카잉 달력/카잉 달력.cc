#include <bits/stdc++.h>

using namespace std;

int T;
int M, N;
int x, y, retY;
bool flag;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		flag = false;

		cin >> M >> N >> x >> y;

		// 멸망해 구하기 ==> 멸망해(M:N)는 두 수의 최소공배수번째 날이다
		int last = lcm(M, N);

		// 두 수의 최소공배수까지 루프를 돌며 x를 고정시키며 y를 찾는다
		for (int i = 0; i * M + x <= last; )
		{
			int day = i * M + x;

			// day(i*M + x 번째 날)의 y값은, day % N이다
			retY = day % N;
			if (retY == 0) retY = N;

			// 찾던 y값이라면
			if (retY == y)
			{
				cout << day << '\n';
				flag = true;
				break;
			}
			else
			{
				//찾던 값이 아니라면
				i++;
			}
		}

		// 루프를 다 돌아도 해당 y값이 없다면 유효하지 않은 해이다
		if(!flag)
			cout << -1 << '\n';
	}
	

	return 0;
};