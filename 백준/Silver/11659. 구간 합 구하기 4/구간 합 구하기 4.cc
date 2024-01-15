#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100004];
int psum[100004];
int here, there;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		psum[i] = psum[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> here >> there;
		cout << psum[there] - psum[here - 1] << '\n';
	}

	
	return 0;
};