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
	string input;
	cin >> input;
	vector<int> resultArr(26);
	for (int i = 0; i < input.size(); i++)
	{
		resultArr[input[i] - 97]++;
	}
	for (int i = 0; i < resultArr.size(); i++)
	{
		//resultArr[i];
		cout << resultArr[i] << " ";
	}

}