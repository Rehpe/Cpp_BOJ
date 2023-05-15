#include <bits/stdc++.h>
using namespace std;

int N;
int num;
int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[num]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		if (arr[i] > 0)
		{
			for (int j = 0; j < arr[i]; j++)
				cout << i << '\n';
		}
	}
	
}