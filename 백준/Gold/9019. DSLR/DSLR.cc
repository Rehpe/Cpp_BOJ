#include <bits/stdc++.h>

using namespace std;

int T;
int A, B;
bool visited[10001];

void bfs(int n)
{
	queue<pair<int, string>> q;

	q.push({ n, "" });
	visited[n] = true;

	while (q.size())
	{
		int cur_num = q.front().first;
		string cur_op = q.front().second;

		q.pop();

		if (cur_num == B)
		{
			cout << cur_op << '\n';
			return;
		}

		int D, S, L, R;

		D = 2 * cur_num % 10000;
		if (!visited[D])
		{
			visited[D] = true;
			q.push({ D, cur_op + "D" });
		}

		S = cur_num - 1;
		if (S == -1) S = 9999;
		if (!visited[S])
		{
			visited[S] = true;
			q.push({ S, cur_op + "S" });
		}

		L = (cur_num % 1000)* 10 + (cur_num / 1000);
		if (!visited[L])
		{
			visited[L] = true;
			q.push({ L, cur_op + "L" });
		}

		R = (cur_num / 10) + (cur_num % 10) * 1000;
		if (!visited[R])
		{
			visited[R] = true;
			q.push({ R, cur_op + "R" });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> A >> B;
		bfs(A);
		memset(visited, 0, sizeof(visited));
	}

	return 0;
};