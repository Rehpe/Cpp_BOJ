#include <bits/stdc++.h>
using namespace std;

int N;
int a[1000004];
vector<int> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}
	
	// 벡터 정렬
	sort(v.begin(), v.end());

	// 중복 제거
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++)
	{
		// lower_bound(a,b,c): a~b 범위 내에서 c가 처음 나오는 idx 반환 
		// 즉, a[i] 값보다 작은 값이 몇개인지 반환함
		int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		cout << idx << ' ';
	}

	return 0;
}