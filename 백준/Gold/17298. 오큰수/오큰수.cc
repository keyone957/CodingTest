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
	int arrLen;
	cin >> arrLen;
	vector<int> numArr(arrLen);
	vector<int> answerArr(arrLen);
	stack<int> stackArr;
	for (int i = 0; i < arrLen; i++)
	{
		cin >> numArr[i];
	}

	for (int i = 0; i < arrLen; i++)
	{
		while (!stackArr.empty() && numArr[i] > numArr[stackArr.top()])
		{
			answerArr[stackArr.top()]= numArr[i];
			stackArr.pop();
		}
		stackArr.push(i);
	}
	
	while (!stackArr.empty())
	{
		answerArr[stackArr.top()] = -1;
		stackArr.pop();
	}
	for (int i = 0; i < arrLen; i++)
	{
		cout << answerArr[i] << " ";
	}
}