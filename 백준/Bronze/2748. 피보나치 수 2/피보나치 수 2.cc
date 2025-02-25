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
long long memo[91] ;
long long int fibo(int a)
{
	if (a == 0)
	{
		memo[a] = 0;
	}
	else if (a == 1)
	{
		memo[a] = 1;
	}
	else if(memo[a]==-1)
		memo[a] = fibo(a-1)+fibo(a-2);
	return memo[a];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(memo, memo + 91, -1);
	int count;
	cin >> count;
	cout << fibo(count);
}