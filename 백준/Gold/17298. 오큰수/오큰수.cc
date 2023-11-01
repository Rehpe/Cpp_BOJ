#include <bits/stdc++.h>

using namespace std;

int N;
int a[1000004], ret[1000004];
stack<int> s;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;

	// -1로 초기화
	memset(ret, -1, sizeof(ret));

	for (int i = 0; i < N; i++)
	{
		// 배열에 value 저장
		cin >> a[i];

		// 이번에 넣는 수가 직전에 넣은 수보다 클 경우
		while (s.size() && a[s.top()] < a[i])
		{
			ret[s.top()] = a[i];
			s.pop();
		}
		// 스택에 인덱스 push
		s.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << ret[i] << ' ';
	}

	return 0;
}