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
//int inputArr[10];
vector<int> inputArr;
void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++)
	{
		if (!isused[i])
		{
			arr[k] = inputArr[i];
			isused[i] = 1;
			func(k + 1);
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
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		inputArr.push_back(input);
	}
	sort(inputArr.begin(), inputArr.end());

	func(0);
}