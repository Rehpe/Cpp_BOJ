#include <bits/stdc++.h>
using namespace std;

int n;
int score;
vector<int> opinion;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score;
		opinion.push_back(score);
	}

	if (n == 0)
		cout << 0;
	else
	{
		// 절사평균할 인원수 구하기 (15%, 반올림)
		int cnt = round(n * 0.15);

		sort(opinion.begin(), opinion.end());

		// 낮은 점수 cnt명, 높은 점수 cnt명 제외 후 평균
		double sum = accumulate(opinion.begin() + cnt, opinion.end() - cnt, 0);

		n -= 2 * cnt;

		cout << round(sum / (double)n);
	}
}

