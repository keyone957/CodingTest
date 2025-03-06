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
		return;
	}
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (!isUsed[i] &&temp != inputArr[i])
		{
			arr[k] = inputArr[i];
			temp = arr[k];
			isUsed[i] = 1;
			func(k + 1);
			isUsed[i] = 0;
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