#include <bits/stdc++.h>

using namespace std;

#define time aaa

int N;
int ans;
int isUsedCol[15];	// 각 열에 대응함
int isUsedRightUp[30]; // 우상향 대각선 칸에 대응함 (x+y 값이 같음)
int isUsedRightDown[30]; // 우하향 대각선 칸에 대응함 (x-y 값이 같음)

void queen(int cnt)
{
	if (cnt == N)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		// i열에 이미 퀸이 있거나 // 우상향 대각선에 걸리거나 // 우하향 대각선에 걸리거나 (인덱스 음수 방지)
		if (isUsedCol[i] || isUsedRightUp[cnt + i] || isUsedRightDown[cnt - i + N - 1])
		{	
			// 넘기기
			continue;
		}

		// 위 조건에 걸리지 않는다면, 현재 놓을 퀸의 좌표를 바탕으로 isUsed 시리즈들을 채운다
		isUsedCol[i] = 1;
		isUsedRightUp[cnt + i] = 1;
		isUsedRightDown[cnt - i + N - 1] = 1;

		// 다음 행(cnt + 1)으로 재귀호출
		queen(cnt + 1);

		// 점유했던 칸을 취소한다
		isUsedCol[i] = 0;
		isUsedRightUp[cnt + i] = 0;
		isUsedRightDown[cnt - i + N - 1] =0;
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	queen(0);	// 0번 행부터 퀸 놓기
	cout << ans;

	return 0;
}