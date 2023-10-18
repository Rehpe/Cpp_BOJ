#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int N, num;
priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		// 첫 요소는 무조건 maxHeap에 넣는다
		if (i == 0)
			maxHeap.push(num);
		else
		{
			if (maxHeap.size() <= minHeap.size())
				maxHeap.push(num);
			else
				minHeap.push(num);
		}

		// maxHeap과 minHeap의 Top을 비교하고 minHeap Top이 maxHeap Top보다 작다면 교체한다
		if (!maxHeap.empty() && !minHeap.empty())
		{
			if (maxHeap.top() > minHeap.top())
			{
				int maxTop = maxHeap.top();
				int minTop = minHeap.top();
				maxHeap.pop();
				minHeap.pop();
				minHeap.push(maxTop);
				maxHeap.push(minTop);
			}
		}
		cout << maxHeap.top() << '\n';
	}
	return 0;
}