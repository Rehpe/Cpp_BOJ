#include <bits/stdc++.h>

using namespace std;

int n;
int U[1001];
vector<int> twosum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> U[i];
	}

	// 받아온 U 배열을 정렬한다.
	sort(U, U + n);

	// 두 개의 원소를 뽑아서 더한 값을 twosum에 저장한다
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int sum = U[i] + U[j];
			twosum.push_back(sum);
		}
	}
	
	//twosum을 오름차순으로 정렬한다.
	sort(twosum.begin(), twosum.end());

	//x+y+z = k가 되는 k를 찾아야 하는데, 두 수의 합은 이미 구해놓음. 따라서 two = z - k 를 만족하는 z 중 가장 큰 값을 찾는다.
	// 가장 큰 값을 빠르게 찾기 위해 오름차순 정렬된 U배열의 마지막 idx부터 찾는다 
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(twosum.begin(), twosum.end(), U[i] - U[j]))
			{
				cout << U[i];
				return 0;
			}
		}
	}
		
	return 0;
}