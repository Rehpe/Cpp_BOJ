#include <bits/stdc++.h>

using namespace std;

#define time aaa

int N, M;
vector<int> arr;
bool visited[10];

void go(vector<int> v)
{
	if (v.size() == M)
	{
		for (auto a : v)
		{
			cout << a << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			arr.push_back(i);
			visited[i] = true;
			go(arr);
			arr.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	go(arr);

	return 0;
}