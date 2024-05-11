#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<>> minPQ;

int sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		maxPQ.push(num);
	}

	// 무조건 최대인 것: 1이 아닌 양수끼리의 곱, 음수끼리의 곱

	// 1. 1이 아닌 양수 쌍이 있으면 무조건 곱한다
	while (maxPQ.size() >=2)
	{
		// 큰 순서대로 두개 뽑기
		int a = maxPQ.top();
		maxPQ.pop();
		int b = maxPQ.top();
		maxPQ.pop();

		// 둘다 1이 아닌 양수인지 확인
		if (a > 1 && b > 1)
			sum += a * b;
		else
		{
			// pop했던 숫자를 다시 넣고 break
			maxPQ.push(a);
			maxPQ.push(b);
			break;
		}
	}

	// maxPQ의 값 minPQ로 옮기기
	while (!maxPQ.empty())
	{
		int num = maxPQ.top();
		maxPQ.pop();
		minPQ.push(num);
	}

	// 2. 음수 쌍이 있으면 무조건 곱한다 (음수 쌍 혹은 음수와 0)
	while(minPQ.size() >=2)
	{
		// 작은 순서대로 두개 뽑기
		int a = minPQ.top();
		minPQ.pop();
		int b = minPQ.top();
		minPQ.pop();

		// 둘 다 음수인지 확인
		if (a <= 0 && b <= 0)
			sum += a * b;
		else
		{
			// pop했던 숫자를 다시 넣고 break
			minPQ.push(a);
			minPQ.push(b);
			break;
		}
	}

	// 3. 나머지는 전부 더한다
	while (minPQ.size())
	{
		int a = minPQ.top();
		minPQ.pop();
		sum += a;
	}

	cout << sum;

	return 0;
}