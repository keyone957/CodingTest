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
	string input;
	cin >> input;
	vector<int> result;
	for (int i = 0; i < input.size(); i++)
	{
		int num = (int)input[i]-'0';
		result.push_back(num);
	}
	int index=0;
	for (int i = 0; i < result.size(); i++)
	{
		int MaxNum = i;
		for (int j = i + 1; j < result.size(); j++)
		{
			if (result[j] > result[MaxNum])
			{
				MaxNum = j;
			}
		}
		if (result[i] < result[MaxNum])
		{
			swap(result[i], result[MaxNum]);
		}
		cout << result[i];
	}
}