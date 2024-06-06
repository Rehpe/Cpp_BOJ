#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> tc;
string dp[102];	//dp[i] = 성냥이 i개 있을 때 만들 수 있는 최소값
string MAX_STR = "11111111111111111111111111111111111111111111111119";	// 1 * 49자리 + 9
int match_require[10] = { 6,2,5,5,4,5,6,3,7,6 };
pair<int, int> match_require_min[7] = { {0,6},{1,2},{2,5},{4,4},{6,6},{7,3},{8,7}};
int x;	// 탐색할 숫자 x;



// 최대값 구하기
// 최대값의 경우 자리수가 길수록 큰 숫자이다
// 문제의 최대 성냥개비 숫자가 100개기 때문에 가능한 최대값은 1을 50번 쓴 50자리 수이다
// int의 경우 10자리, long long의 경우 20자리를 표현할 수 있기 때문에 이 문제는 string으로 풀어야한다

// 큰 자리수를 만들기 위해서는 최소의 성냥개비로 많은 자리수를 표현해야한다
// 따라서 성냥개비 수가 짝수라면 모조리 1로 만들고,
// 성냥개비 수가 홀수라면 7을 한 번 만든 후 나머지를 1로 채우면 된다
string findMax(int left)
{
	string ret = "";

	// 홀수라면
	if (left & 1)
	{
		ret += "7";
		left -= 3;
	}

	while (left)
	{
		left -= 2;
		ret += "1";
	}

	return ret;
}

// 최소값 구하기
// 최소값의 경우 최대값처럼 자리수가 클수록 크다 같이 그리디하게 풀 수 없다
// 따라서 dp테이블을 만들어서 풀이해야한다

// 최소값은 min함수로 비교하여 작은 쪽을 저장해야하기 떄문에 초기값이 최대값이어야한다
// 해당 문제의 최대값은 50자리 수이기 때문에 숫자가 아닌 string으로 비교해야하기 때문에 비교를 위한 함수가 필요하다

string findMinString(string a, string b)
{
	if (a.size() == b.size())
	{
		if (a > b) return b;
		else return a;
	}
	if (a.size() > b.size())
		return b;
	else
		return a;
}

// Top-Down 방식
string findMin(int left)
{
	// 남은 성냥이 없다면 탐색 완료
	if (left == 0) return "";

	// 갱신된 적 있는 값이라면 해당 값 반환
	if (dp[left] != MAX_STR) return dp[left];

	//for (int i = 0; i <= 9; i++)	// 가능한 숫자 0~9에 대해 탐색
	for(int i =0; i< 7; i++)	// 최소화한 0,1,2,4,6,7,8 에 대해서만 탐색
	{
		int num = match_require_min[i].first;
		int required_match = match_require_min[i].second;

		if (left - required_match < 0) continue; // 남은 성냥 수보다 필요 성냥수가 많다면 skip
		if (left == x && num == 0) continue; // 첫번째 숫자에 0이 오는 것을 방지

		dp[left] = findMinString(dp[left], to_string(num) + findMin(left - required_match));
	}
	return dp[left];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	
	// 최소값을 위한 dp테이블 초기화
	fill(dp, dp + 102, MAX_STR);
	dp[0] = "";

	//Bottom-up
	for (int i = 2; i < 101; i++)	// 남은 성냥 수
	{
		for (int j = 0; j < 7; j++) // 최소화한 0,1,2,4,6,7,8 에 대해서만 탐색
		{
			int num = match_require_min[j].first;
			int required_match = match_require_min[j].second;

			if(i - required_match < 0) continue; // 남은 성냥 수보다 필요 성냥수가 많다면 skip
			if (num == 0 && dp[i - required_match] == "") continue;	// 첫번째 숫자에 0이 오는 것을 방지

			dp[i] = findMinString(dp[i], dp[i - required_match] + to_string(num));
		}
	}

	while (t--)
	{
		cin >> x;
		cout << dp[x] << " " << findMax(x) << "\n";
		//cout << findMin(x) << " " << findMax(x) << "\n";
	}

	return 0;
}