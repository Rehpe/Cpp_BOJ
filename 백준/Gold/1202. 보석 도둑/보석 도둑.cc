#include <bits/stdc++.h>

using namespace std;

int n, k;
long long sum;

pair<int, int> gem[300001];
int bagweight[300001];

priority_queue<pair<int, int>> bag;	// 가치-무게 순. 가치가 높은 순으로 정렬됨

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int weight, value;
		cin >> weight >> value;
		gem[i] = { weight, value };
	}

	for (int i = 0; i < k; i++)
	{
		cin >> bagweight[i];
	}

	// 무게가 낮은 순으로 보석 정렬
	sort(gem, gem + n);

	// 가방 한도가 작은 순서로 정렬
	sort(bagweight, bagweight + k);

	int index = 0;
	
	for (int i = 0; i < k; i++)
	{
		// i 번째 가방 한도보다 무게가 낮은 보석을 bag에 넣는다
		for (int j = index; j <n; j = index)
		{
			if (bagweight[i] >= gem[j].first)
			{
				bag.push({ gem[j].second, gem[j].first });
				index++;
			}
			else
				break;	// 무게가 낮은 순이므로 벗어나면 바로 break;
		}

		if (!bag.empty())
		{
			// i번째 가방 한도 내에서 가장 가치가 높은 보석이 top에 있으므로 해당 보석 가치를 더함
			sum += bag.top().first;

			bag.pop();
		}
	}

	cout << sum;
}