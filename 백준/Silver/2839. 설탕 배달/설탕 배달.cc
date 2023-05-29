#include <bits/stdc++.h>
using namespace std;

int N;
int ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	while (true)
	{
		if (N % 5 == 0)	// N이 5의 배수일 때
		{
			ret += N / 5;	// 결과값에 5로 나눈 수 추가
			cout << ret;	
			break;
		}
		
		// N이 5의 배수가 아니라면, 3을 빼고 결과값에 1 추가 (3kg 설탕 한봉지 추가)
		N -= 3;
		ret++;

		if (N < 0)	// N이 음수가 되었다면 -> 구성 불가능, -1 출력
		{
			cout << -1;
			break;
		}
	}
}
