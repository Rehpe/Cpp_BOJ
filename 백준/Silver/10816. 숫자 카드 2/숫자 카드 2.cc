#include <bits/stdc++.h>
using namespace std;

int N, M;
int num;
vector<int> card;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		card.push_back(num);
	}
	sort(card.begin(), card.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		cout << upper_bound(card.begin(), card.end(), num) -
			lower_bound(card.begin(), card.end(), num) << " ";
	}
}