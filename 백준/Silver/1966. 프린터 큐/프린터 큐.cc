#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int value;
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> value;	
			q.push({ j, value });		// 인덱스, 중요도
			pq.push(value);				// 중요도
		}

		cnt = 1;

		while (!q.empty())
		{
			int idx = q.front().first;
			value = q.front().second;

			if (q.front().second != pq.top())	// 중요도가 가장 높은 문서가 아닐 경우
			{
				q.pop();
				q.push({ idx, value });
			}
			else  // 중요도가 가장 높은 문서일 경우
			{
				if (q.front().first == M)	// 찾고 있는 문서라면 break
					break;
				else
				{
					q.pop();
					pq.pop();
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}


}