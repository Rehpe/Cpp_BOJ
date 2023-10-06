#include <bits/stdc++.h>
using namespace std;

int N;
string s;
char a[101][101];

string quad(int y, int x, int size)
{
	if (size == 1)
		return string(1, a[y][x]);	// a[y][b]문자열을 1번만 반환하는 함수(즉, 앞 인자가 1일 경우 char을 string으로 반환) 

	// 검사할 블럭의 첫 번째 문자(0 또는 1)
	char b = a[y][x];

	string ret = "";	// 결과 반환용 string 선언

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			// size 전체를 탐색하여, b와 다른 문자가 하나라도 있다면 
			if (b != a[i][j])
			{
				ret += '(';
				ret += quad(y, x, size / 2);
				ret += quad(y, x + size / 2, size / 2);
				ret += quad(y + size / 2, x, size / 2);
				ret += quad(y + size / 2, x + size / 2, size / 2);
				ret += ')';

				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// string으로 줄줄이 들어온 입력을 char 형태로 나눠서 저장
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			a[i][j] = s[j];
		}
	}

	cout << quad(0, 0, N) << '\n';
}
