#include <bits/stdc++.h>

using namespace std;

int k;
int n, c, l;	// n: 친구 수 c: 자동차 수 l: 지역 수
int drunkfriend[501];
int nondrunkfriend[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	for(int tc = 1; tc <= k; tc++)
	{
		cin >> n >> c >> l;

		memset(drunkfriend, 0, sizeof(drunkfriend));
		memset(nondrunkfriend, 0, sizeof(nondrunkfriend));
		vector<pair<int, int>> carinfos;
		int totalfriend = n;

		for (int i = 0; i < n; i++)
		{
			int num;
			char drink;
			cin >> num >> drink;
			if (drink == 'I') drunkfriend[num]++;
			else nondrunkfriend[num]++;
		}

		for (int i = 0; i < c; i++)
		{
			int num;
			int limit;
			cin >> num >> limit;
			carinfos.push_back({ limit, num });
		}

		// 안 취한 사람부터, 인원수가 많은 차부터 타야함

		// 자동차 정보를 인원수가 많은 순으로 정렬
		sort(carinfos.begin(), carinfos.end(), greater<>());

		// 안 취한 사람부터 배정
		for (auto &carinfo : carinfos)
		{
			int limit = carinfo.first;
			int region = carinfo.second;

			if (nondrunkfriend[region] > 0)
			{
				nondrunkfriend[region]--;
				carinfo.first--;
				totalfriend--;
			}
			else
			{
				// 안 취한 사람이 한 명도 타지 않았다면 운행 불가능하므로 인원수 0
				carinfo.first = 0;
			}
		}

		// 안 취한 사람 배정이 끝나면 남은 자리를 배정

		for (auto &carinfo : carinfos)
		{
			int limit = carinfo.first;
			int region = carinfo.second;

			while (true)
			{
				if (carinfo.first <= 0) break;

				if (nondrunkfriend[region] > 0)
				{
					nondrunkfriend[region]--;
					carinfo.first--;
					totalfriend--;
				}
				else if (drunkfriend[region] > 0)
				{
					drunkfriend[region]--;
					carinfo.first--;
					totalfriend--;
				}
				else break;
			}
		}

		cout << "Data Set " << tc << ":" << '\n' << totalfriend <<'\n';
	}

	return 0;
}