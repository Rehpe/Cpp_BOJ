#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> endtime;
int start, finish;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		start = v[i].first;
		finish = v[i].second;

		if (endtime.empty())
		{
			endtime.push(finish);
			continue;
		}

		// 끝나는 시간이 가장 이른 강의실만 검사한다.
		int earliestfinish = endtime.top();

		if (start >= earliestfinish)
		{
			endtime.pop();
			endtime.push(finish);
		}
		else
			endtime.push(finish);
	}

	cout << endtime.size();
}



