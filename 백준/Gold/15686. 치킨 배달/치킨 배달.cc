#include <bits/stdc++.h>
using namespace std;

int N, M;	// N: 도시 크기(최대 50), M: 남길 치킨집 개수(최대 13)
// 최대 집의 개수는 2N개이므로, 집의 최대범위는 100

int maps[51][51];
vector<vector<int>> chickenList; // 치킨집 조합 리스트
vector<pair<int, int>> houses;	// 전체 집 좌표가 들어있는 리스트
vector<pair<int, int>> chicken; // 전체 치킨집의 좌표가 들어있는 리스트
int result = INT_MAX;

void combi(int start, vector<int> vec)
{
	// 최대 치킨집 수를 달성하면 조합리스트에 넣고 return
	if (vec.size() == M)
	{
		chickenList.push_back(vec);
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++)
	{
		vec.push_back(i);
		combi(i, vec);
		// M개의 조합을 완성해서 이 부분으로 돌아오면 마지막 인덱스를 하나 빼며 BackTracking
		vec.pop_back();
	}
	return;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 1)	// 집이라면
				houses.push_back({ i, j });
			else if (maps[i][j] == 2) // 치킨집이라면
				chicken.push_back({ i, j });
		}
	}

	vector<int> temp; // 임시 벡터
	combi(-1, temp);	// 임시 벡터에 치킨집 좌표를 채워가며 조합 뽑아 ChickenList 채움

	// 치킨리스트의 M개로 구성된 조합을 하나씩 탐색
	for (vector<int> cList : chickenList)
	{
		int ret = 0;
		// 맵의 모든 집에 대해서 치킨집과의 최소거리 구하기
		for (pair<int, int> house : houses)
		{
			int minDist = INT_MAX;
			// 탐색 중인 집과 cList의 치킨집 중 최소거리 구하기 
			for (int chickenIdx : cList)
			{
				int Dist = abs(house.first - chicken[chickenIdx].first) + abs(house.second - chicken[chickenIdx].second);
				minDist = min(minDist, Dist);
			}
			ret += minDist;
		}
        
		result = min(result, ret);
	}

	cout << result;

	return   0;
}