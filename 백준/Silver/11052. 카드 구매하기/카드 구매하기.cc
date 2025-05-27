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
int card[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cardCount;
	cin >> cardCount;
	for (int i = 1; i <= cardCount; i++)
	{
		cin >> card[i];
	}
	card[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= cardCount; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[cardCount];
}