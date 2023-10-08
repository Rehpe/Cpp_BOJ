#include <bits/stdc++.h>
using namespace std;

int N, M, J;	// N: 스크린 칸 개수, M: 바구니 칸, J: 떨어질 사과 개수
int ret;
int cnt;


int go(int& head, int& tail, int line)
{
	if (head <= line && line <= tail)
		return 0;
	else if (tail < line)
	{
		head++;
		tail++;
		return 1 + go(head, tail, line);
	}
	else if( line < head)
	{
		head--;
		tail--;
		return 1 + go(head, tail, line);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> J;
	
	int head = 0;
	int tail = M - 1;

	for (int i = 0; i < J; i++)
	{
		int line;
		cin >> line;

		ret += go(head, tail, line-1);
	}

	cout << ret;
}
