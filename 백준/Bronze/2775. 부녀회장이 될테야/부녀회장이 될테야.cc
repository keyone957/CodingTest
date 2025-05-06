#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int dp[20][20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i <= 14; i++)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 0; j <= 14; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	int count;
	cin >> count;
	vector<int> answer;
	for (int i = 0; i < count; i++)
	{
		int a, b;
		cin >>a >>b;
		answer.push_back(dp[a][b]);
	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i]<<"\n";
	}

}