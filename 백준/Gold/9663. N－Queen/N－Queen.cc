#include <bits/stdc++.h>

using namespace std;

#define time aaa

int N;
int row[15];
int ans;

void queen(int cnt)
{
	// n번째 행까지 퀸을 다 놓았다면 ans++
	if (cnt == N)
	{
		ans++;
		return;
	}


	for (int i = 0; i < N; i++)
	{
		// 2차원 배열을 1차원 배열로 표현하기 위해 row의 idx를 행, 값을 열로 나타낸다.

		// cnt번째 행 퀸 위치를 정함
		row[cnt] = i;
		
		bool able = true;
		// cnt 이전 열까지 놓았던 퀸의 위치를 바탕으로 가로-세로-대각선을 확인해서 
		// 정한 위치(row[cnt] = i)에 퀸을 놓는 것이 가능한지 체크함
		for (int j = 0; j < cnt; j++)
		{
			// 열이 같거나         // 오른쪽 대각선에 걸리거나 // 왼쪽 대각선에 걸리거나
			if (row[cnt] == row[j] || cnt - i == j - row[j] || cnt + i == j + row[j])
			{
				able = false;
				break;
			}
		}
		// 위의 모든 경우에서 가능한 경우에만 실제로 퀸을 놓고 다음 행으로 넘어감
		if (able)
		{
			queen(cnt + 1);
		}
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