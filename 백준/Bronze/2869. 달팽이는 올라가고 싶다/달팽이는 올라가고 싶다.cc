#include <bits/stdc++.h>
using namespace std;

int A, B, V;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> V;

	//int h = 0;		// 달팽이의 현재 높이
	//int days = 0;	// 걸린 날짜

	//while (true)
	//{
	//	days++;
	//	h += A;
	//	if (h >= V)
	//		break;
	//	h -= B;
	//}

	//cout << days;

	int ret = ceil((double)(V - B) / (double)(A - B));

	cout << ret;
}