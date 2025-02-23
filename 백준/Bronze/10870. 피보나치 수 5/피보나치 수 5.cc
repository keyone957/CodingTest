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
int func(int a)
{
	if (a == 0)
	{
		return 0;
	}
	else if (a == 1)
	{
		return 1;
	}
	else
	{
		return func(a - 1) + func(a - 2);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a;
	cin >> a;
	cout << func(a);
}