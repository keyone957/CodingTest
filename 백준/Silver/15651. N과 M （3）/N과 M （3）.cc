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
int n, m;
int arr[10];
int isused[10];
void func(int a)
{
	if (a == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			arr[a] = i;
			/*isused[i] = 1;*/
			func(a + 1);
			isused[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(0);
}