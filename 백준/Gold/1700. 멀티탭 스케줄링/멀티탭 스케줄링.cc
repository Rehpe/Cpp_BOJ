#include <bits/stdc++.h>

using namespace std;

int n, k;
int order[101];			 // 사용 순서
bool isUsingPlug[101];	 // i번 플러그가 사용중인지 여부
vector<int> multi;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> order[i];
	}

	int plugout = 0;

	for (int i = 0; i < k; i++)
	{
		int plug = order[i];

		// 1. 이미 꽂혀있는 경우
		if (isUsingPlug[plug]) continue; // 패스
	
		// 2. 꽂을 자리가 있는 경우
		else if (multi.size() < n)
		{
			// 사용 플러그 true 처리 후 벡터에 push
			isUsingPlug[plug] = 1;
			multi.push_back(plug);
		}
		// 3. 꽂을 자리가 없는 경우
		else
		{
			int maxuseidx = -1; // 가장 나중에 사용할 순서
			int outplug = -1; // 뽑힐 플러그

			// 남은 사용 순서를 파악하여 가장 나중에 사용할 플러그를 뽑는다
			for (int plugidx : multi)
			{
				int nextuse = -1;	// 다음에 사용할 순서

				for (int j = i+1; j < k; j++)
				{
					if (plugidx == order[j])
					{
						nextuse = j;
						break;
					}
				}
				// 이후에 쓰이지 않는다는 의미로, 빼야할 1순위임
				if (nextuse == -1)
					nextuse = INT_MAX;

				maxuseidx = max(maxuseidx, nextuse);
				if (maxuseidx == nextuse)
					outplug = plugidx;
			}

			plugout++;
			isUsingPlug[outplug] = false;
			multi.erase(find(multi.begin(), multi.end(), outplug));

			isUsingPlug[plug] = true;
			multi.push_back(plug);
		}
	}

	cout << plugout;

	return 0;
}
