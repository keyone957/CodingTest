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
int dp[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10001; i++)
	{
		dp[i] = 1;
	}
	for (int i = 2; i < 10001; i++)
	{
		dp[i] += dp[i - 2];
	}
	for (int i = 3; i < 10001; i++)
	{
		dp[i] += dp[i - 3];

	}
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		cout << dp[input]<<'\n';
	}
}