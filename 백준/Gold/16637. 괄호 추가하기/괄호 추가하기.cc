#include <bits/stdc++.h>

using namespace std;

int N;
int x;
char c;
int ret = INT_MIN;
vector<int> nums;
vector<char> oper;

int opers(char oper, int a, int b)
{
	if (oper == '+')	return a + b;
	else if (oper == '-') return a - b;
	else if (oper == '*') return a * b;
}

// go 함수 인자의 이해
// curIdx 까지의 누적합이 sum이라고 생각하면 된다
// 첫 인자로 들어가는 go(0, nums[0]) 의 경우: 0번째 인덱스의 정수까지의 합은 해당 정수값 그대로일것이다
void go(int curIdx, int sum)
{
	// 모든 정수에 대한 계산을 마쳤다면
	if (curIdx == nums.size() - 1)
	{
		ret = max(ret, sum);
		return;
	}

	// 현재 인자로 들어온 정수 Idx부터 정수 3개, 연산자 2개씩 끊어서 생각해보자 (a x b y c)
	
	// 앞부분에 괄호를 치는 경우 계산 ex: ( a x b ) y c
	go(curIdx + 1, opers(oper[curIdx], sum, nums[curIdx + 1]));	// curIdx +1 까지의 합은 직전까지의 합 + 다음 정수와 연산자 결과의 합
	

	// 뒷부분에 괄호를 치는 경우 계산 ex : a x (b y c)
	if (curIdx + 2 <= nums.size() - 1)	// 오버플로우 방지
	{
		int temp = opers(oper[curIdx + 1], nums[curIdx + 1], nums[curIdx + 2]);
		go(curIdx + 2, opers(oper[curIdx], sum, temp)); // curIdx + 2까지의 합은 직전까지의 합 + 다음정수, 다다음정수와 연산자 결과의 합
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// 짝수라면 자연수(0~9)
		if (i % 2 == 0)
		{
			cin >> x;
			nums.push_back(x);
		}
		// 홀수라면 연산자
		else
		{
			cin >> c;
			oper.push_back(c);
		}
	}

	go(0, nums[0]);

	cout << ret;

}