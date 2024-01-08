#include <bits/stdc++.h>
#define time aaa
#define end bbb

using namespace std;

int N;
pair<int, int> time;
int cnt;

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		// 끝나는 시간이 같다면 시작 시간이 빠른 것부터
		if (a.second == b.second)
			return a.first > b.first;
		// 끝나는 시간이 빠른 순서부터
		else
			return a.second > b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		pq.push({ x, y });
	}

	int end = 0;

	while (pq.size())
	{
		int x, y;
		tie(x, y) = pq.top();

		// 직전의 회의가 끝난 시간보다 다음 시작 회의의 시작시간이 이후라면
		if (end <= x)
		{
			cnt++; // 회의 카운트 ++
			end = y;// 직전 회의 끝난 시간 갱신
		}
		pq.pop();
	}

	cout << cnt;
	return 0;

};