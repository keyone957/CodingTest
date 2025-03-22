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
int arr[20];
int isused[20];
int sum = 0;
int result1 = 0;
vector<int> arrInput;
void Func(int k,int sum)
{
	if (k == n)
	{
		if (sum == m)
		{
			result1++;
		}
		return;
	}
		//sum += arr[k];
	Func(k + 1, sum + arrInput[k]);
	Func(k + 1,sum);
		
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
	Func(0,0);
	if (m == 0) result1--;
	cout << result1;
}