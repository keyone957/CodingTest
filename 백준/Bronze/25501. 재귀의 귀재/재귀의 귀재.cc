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
#include <cstring>
#include <vector>
using namespace std;
int countR;
int recursion(const char* s, int l, int r)
{
	countR++;
	if (l >= r)
	{
		return 1;
	}
	else if (s[l] != s[r])
	{
		return 0;
	}
	else
	{
		return recursion(s, l + 1, r - 1);
	}
}
int isPal(const char* s)
{
	return recursion(s, 0, strlen(s) - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		string input;
		cin >> input;
		cout << isPal(input.c_str())<<" "<< countR;
		cout << "\n";
		countR = 0;
	}

}