#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	vector<int>arr2;
	for (int i = 0; i < 9; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
		arr2.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int maxNum = arr[8];
	cout << maxNum<<"\n";
	int index = 1;
	for (int i = 0; i < 9; i++)
	{
		if (arr2[i]==maxNum)
		{
			cout << index;
		}
		else
		{
			index++;
		}
	}
}