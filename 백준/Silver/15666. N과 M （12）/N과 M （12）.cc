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
int isUsed[10];
vector<int> arrInput;
void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp != arrInput[i])
		{
			if (k == 0 || arr[k-1] <= arrInput[i])
			{
				arr[k] = arrInput[i];
				temp = arrInput[i];
				func(k + 1);
			}
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
		arrInput.push_back(input);
	}
	sort(arrInput.begin(), arrInput.end());
	func(0);
}