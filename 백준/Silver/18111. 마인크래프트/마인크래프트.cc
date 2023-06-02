#include <bits/stdc++.h>
using namespace std;

int N, M, B;
int height;
int second;
vector<int> ground;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int n;
			cin >> n;
			ground.push_back(n);
		}
	}

	sort(ground.begin(), ground.end());

	int tiles = accumulate(ground.begin(), ground.end(), 0);

	int low = 0;
	int high = 256;
	height = 0;				// 고른 땅의 최종 높이
	int anstime = INT_MAX;	// 정답 시간
	vector<pair<int, int>> anslist;		// 땅 높이, 걸린 시간 순으로 담을 중복정답용 벡터


	// 고를 수 있는 최대 높이의 땅 구하기
	int maxheight = (B + tiles) / (N * M);

	// 최대 높이의 땅 크기만큼 반복문 돌기
	for (int i = 0; i < maxheight + 1; i++)
	{
		second = 0;				// 땅을 고르는 데 걸린 시간

		for (int j = 0; j < N * M; j++)
		{

			// 고를 땅 높이보다 원래 땅이 더 높다면
			if (ground[j] > i)
			{
				// ground[j] - i 칸만큼 블럭 제거
				second += (ground[j] - i) * 2;
			}
			// 고를 땅 높이보다 원래 땅이 더 낮다면
			else if (ground[j] < i)
			{
				// mid - ground[i] 칸만큼 블럭 설치
				second += i - ground[j];
			}
			else // 땅 높이가 같다면
				continue;
		}

		// 기존 기록된 시간보다 작을 경우
		if (second < anstime)
		{
			// 정답리스트 초기화
			anslist.clear();

			// 정답 후보 땅높이-시간 순으로 추가
			anstime = second;
			height = i;
			anslist.push_back(make_pair(height, anstime));
		}
		// 기존 기록된 시간과 같을 경우
		else if (second == anstime)
		{
			anstime = second;
			height = i;
			anslist.push_back(make_pair(height, anstime));
		}
	}
		
	// anslist 정렬 (땅 높이가 높은 순으로)
	sort(anslist.begin(), anslist.end(), greater<pair<int, int>>());

	cout << anslist[0].second << ' ' << anslist[0].first;
}

