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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long d[1500001];
	long long t[1500001];
	long long p[1500001];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}
	for (int i = n; i > 0; i--)
	{
		if (i + t[i] > n + 1)
		{
			d[i] = d[i + 1];
		}
		else
		{
			d[i] = max(d[i + 1], p[i] + d[i + t[i]]);
		}
	}
	cout << d[1];
}