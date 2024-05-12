#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<pair<int, int>> ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater< >> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());

	for (auto a : v)
	{
		int start = a.first;
		int end = a.second;

		if (ret.empty())
		{
			ret.push_back({ start, end });
			continue;
		}

		for (int i = 0; i < ret.size();)
		{
			int x, y;
			x = ret[i].first;
			y = ret[i].second;

			if (start >= x && end <= y)
			{
				// 기존 범위 내인 경우 아무 일도 일어나지 않음
				break;
			}
			else if (start <= y && end > y)
			{
				// 선의 끝점만 갱신함
				ret[i] = { x, end };
				break;
			}
			else if (start > y)
			{
				// 다음 검사할 선이 없으면 새로 추가
				if (i + 1 >= ret.size())	ret.push_back({ start, end });
				else
				{
					// 다음 검사할 선이 있다면 다음 선에 대하여 검사
					i++;
				}
			}
		}
	}

	int sum = 0;
	for (auto a : ret)
	{
		sum += a.second - a.first;
	}
	cout << sum;

	return 0;
}