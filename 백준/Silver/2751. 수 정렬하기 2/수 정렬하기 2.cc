#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int a;
	cin >> a;
	vector<int>arr;

	for (int i = 0; i < a; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i]<<"\n";
	}

}