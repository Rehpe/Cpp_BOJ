#include <bits/stdc++.h>

using namespace std;

int N, r, c;
int cnt;

// y, x : 탐색할 사분면의 가장 좌측상단 칸의 좌표
// size : 탐색할 사분면의 크기(한 변의 길이)
void go(int y, int x, int size)
{
	// 구하고자 하는 좌표에 도달했다면 출력 후 return
	if(y == r &&  x == c)
	{
		cout << cnt;
		return;
	}

	// 구하고자 하는 좌표 r, c가 현재 사분면 내에 존재하는가?
	if (r >= y && r < y + size && c >= x && c < x + size)
	{
		// 1사분면 탐색
		go(y, x, size / 2);
		
		// 2사분면 탐색
		go(y, x + size / 2, size / 2);

		// 3사분면 탐색
		go(y + size / 2, x, size / 2);

		// 4사분면 탐색
		go(y + size / 2, x + size / 2, size / 2);
	}
	else
	{
		// 해당 사분면 안에 구하고자 하는 좌표가 없다면, 
		// 해당 사분면의 넓이만큼 cnt에 추가해주고 다음 사분면을 검색한다. 
		// (해당 사분면 안에 좌표가 없다면 통째로 사분면 하나의 넓이(포함하는 칸 수)를 더해버리는 식으로
		// 일일이 좌표마다 칸을 세지 않는다)
		cnt += size * size;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> r >> c;
	go(0, 0, pow(2, N));

	return 0;
}