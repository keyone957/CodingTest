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
	
	for (int i = 0; i < count; i++)
	{
		list<char> arr = {};
		string s;
		
		//list<char>::iterator r = arr.begin();
		auto r = arr.begin();
		cin >> s;
		for (auto a : s)
		{
			if (a == '<')
			{
				if (r != arr.begin())
				{
					r--;
				}
			}
			else if (a == '-')
			{
				if (r != arr.begin())
				{
					r--;
					r = arr.erase(r);
				}
			}
			else if (a == '>')
			{
				if (r!=arr.end())
				{
					r++;
				}
			}
			else
			{
				arr.insert(r,a);
			}
			
		}
		for (auto l : arr)
		{
			cout << l;
		}
		cout << "\n";
	}
	
}