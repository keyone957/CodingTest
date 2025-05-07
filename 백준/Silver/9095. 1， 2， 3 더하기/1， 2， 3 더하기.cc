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
int dp[11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	cin >> count;
	for (int i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < count; i++)
	{
		int n;
		cin >>n;
		cout << dp[n] << "\n";
	}
}