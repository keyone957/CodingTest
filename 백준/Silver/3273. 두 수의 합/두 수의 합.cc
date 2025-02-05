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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	vector<int> numArr;
	int answerNum=0;
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		numArr.push_back(input);
	}
	sort(numArr.begin(), numArr.end());
	cin >> answerNum;
	int startIndex=0;
	int endIndex=count-1;
	int answerCount = 0;
	while (startIndex < endIndex)
	{
		if (numArr[startIndex] + numArr[endIndex] < answerNum)
		{
			startIndex++;
		}
		else if (numArr[startIndex] + numArr[endIndex] > answerNum)
		{
			endIndex--;
		}
		else
		{
			answerCount++;
			startIndex++;
			endIndex--;
		}
	}
	cout << answerCount;
}