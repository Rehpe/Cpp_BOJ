#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;
int minXmove, minYmove;

int main()
{
	cin >> x >> y >> w >> h;

	// 각 꼭지점 (0,0), (w,0), (w,h), (0,h)
	// 경계선 = x좌표가 0이거나 w이거나 / y좌표가 0이거나 h이거나

	// x축 기준, 0과 w 중 더 가까운(수가 작은) 곳
	minXmove = min(x - 0, w - x);

	// y축 기준, 0과 h 중 더 가까운 곳
	minYmove = min(y - 0, h - y);

	// 둘 중 더 작은 수 출력
	cout << min(minXmove, minYmove);
}