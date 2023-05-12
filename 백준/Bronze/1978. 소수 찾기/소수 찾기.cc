#include <bits/stdc++.h>
using namespace std;

int N;
int nums;

int main()
{
	// 소수란? 1과 자기 자신 외에 나누어 떨어지는 수가 없는 수
	// 소수를 효과적으로 판별하는 법
	// >> 본인의 제곱근까지의 수까지만 확인하면 그 이후로는 대칭적으로 동일하다

	// 범위에 대한 소수 판별 : 에라토스테네스의 체
	// 2부터 N까지 모든 자연수를 나열하고
	// 남은 수 중 처리하지 않은 가장 작은 수 i를 찾아 남은 수에서 i를 제외한 i의 배수를 제거

	// 최대값 1000에 대하여 에라토스테네스의 체로 미리 소수 데이터를 만들어둔다.
	int primeData[1001] = {};
	fill(&primeData[0],&primeData[1001], 1);
	
	// 0, 1은 소수가 아니므로 0 대입
	primeData[0] = 0;
	primeData[1] = 0;

	for (int i = 2; i < sqrt(1000) +1; i++)
	{
		if (primeData[i])	// 데이터값이 1(true)라면
		{
			for (int j = i*2; j < 1001; j +=i)	// i 본인은 제외하고 2배수부터 지워야하므로 i*2로 시작함
			{
				primeData[j] = 0;
			}
		}
	}

	cin >> N;
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> nums;
		if (primeData[nums])
			ret++;
	}

	cout << ret;
}