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
	int count,rank;
	cin >> count >> rank;
	vector<int> arr(count);
	for (int i = 0; i < count; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << arr[arr.size() - rank];
}