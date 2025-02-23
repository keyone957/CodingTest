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
long long func(int n)
{
	if (n <=1)
	{
		//cout << result;
		return 1;
	}
	return n*func(n - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a;
	cin >> a;
	cout << func(a);
}