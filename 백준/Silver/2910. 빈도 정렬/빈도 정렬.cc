#include <bits/stdc++.h>
using namespace std;

int N, C, a[1001];
int num;
map<int, int> mp;
map<int, int> mp_first;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		// 빈도수가 같을 경우 first 배열에서 더 먼저 나온(수가 작은) 쪽 반환
		return mp_first[a.first] < mp_first[b.first];
	}
	else
	{
		// 빈도수가 많은 쪽을 반환
		return a.second > b.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		//// 입력 순서대로 기록
		//a[i] = num;

		// 첫번째 맵에 카운팅
		mp[num]++;

		// 입력한 숫자가 언제 첫번째로 등장하는지 두번째 맵에 체크
		if (mp_first[num] == 0)
			mp_first[num] = i + 1;
	}

	for (auto it : mp)
	{
		vec.push_back(make_pair(it.first, it.second));	// first : 숫자 second : 빈도수
	}
	sort(vec.begin(), vec.end(), cmp);
	
	for (auto it: vec)
	{
		for (int i = 0; i < it.second; i++)
		{
			cout << it.first << " ";
		}
	}
}
