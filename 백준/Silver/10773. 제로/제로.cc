#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	vector<int> input(count);
	for (int i = 0; i < count; i++)
	{
		cin >> input[i];
	}
	stack<int> resultArr;
	for (int i = 0; i < count; i++)
	{
		if (input[i] == 0)
		{
			resultArr.pop();
		}
		else
		{
			resultArr.push(input[i]);
		}
	}
	int an = 0;
	int resultArrSize=resultArr.size();

	for (int i = 0; i < resultArrSize; i++)
	{
		an += resultArr.top();
		resultArr.pop();
	}
	cout << an;
}