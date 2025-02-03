#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >>count;
	vector<pair<int, int>> arr(count);
	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;
		arr[i].first = num;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());
	vector<int>calArr;
	for (int i = 0; i < count; i++)
	{
		calArr.push_back(arr[i].second - i);
	}
	int maxNum = *max_element(calArr.begin(), calArr.end());
	cout << maxNum+1;
}