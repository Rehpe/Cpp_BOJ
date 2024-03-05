#include <bits/stdc++.h>

using namespace std;

int T;
int num;
string c, x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		priority_queue<int, vector<int>, greater<>> minHeap;
		priority_queue<int> maxHeap;
		map<int, int> poppable;

		cin >> num;

		for (int i = 0; i < num; i++)
		{
			cin >> c >> x;
			if (c == "I")
			{
				int y = stoi(x);

				maxHeap.push(y);
				minHeap.push(y);
				
				// 등록한 적 없는 수라면 1 대입, 등록한 적 있는 수라면 숫자 ++
				if (poppable.count(y) == 0)
					poppable[y] = 1;
				else
					poppable[y]++;
			}
			else if (c == "D")
			{
				if (x == "1")
				{
					// 힙에 요소는 있으나 top이 이미 pop된 상황이라면 -> 다시 pop해서 top을 refresh
					while (!maxHeap.empty() && !poppable[maxHeap.top()]) maxHeap.pop();
					if(!maxHeap.empty())
					{
						// pop할 top요소 배열에 pop되었다는 의미로 --해줌
						poppable[maxHeap.top()]--;
						maxHeap.pop();
					}
				}
				else
				{
					while (!minHeap.empty() && poppable[minHeap.top()] == 0) minHeap.pop();
					if (!minHeap.empty())
					{
						// pop할 top요소 배열에 pop되었다는 의미로 --해줌
						poppable[minHeap.top()]--;
						minHeap.pop();
					}
				}
			}
		}

		// 이미 삭제된 요소가 top일 경우를 방지하여 pop해준다
		while (!maxHeap.empty() && poppable[maxHeap.top()] == 0) maxHeap.pop();
		while (!minHeap.empty() && poppable[minHeap.top()] == 0) minHeap.pop();

		if (maxHeap.empty() && minHeap.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << maxHeap.top() << ' ' << minHeap.top() << '\n';
		}
	}

	return 0;
};