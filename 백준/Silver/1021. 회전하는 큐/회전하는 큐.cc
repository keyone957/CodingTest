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
	int N, M;
	/*N => 큐의 크기
	M=> 뽑아내려고 하는 수의 개수
	10 3
	2 9 5
	1 2 3 4 5 6 7 8 9 10


	*/
	cin >> N >> M;
	deque<int> dArr;
	for (int i = 1; i <= N; i++)
	{
		dArr.push_back(i);
	}
	int result = 0;
	for (int i = 0; i < M; i++)
	{
		int findNum;
		cin >> findNum;
		int distanceIdx = find(dArr.begin(), dArr.end(), findNum) - dArr.begin() ;
		//cout << distanceIdx<<endl;
		int size = dArr.size() / 2;
		while (1)
		{
			if (dArr.front() == findNum)
			{
				dArr.pop_front();
				break;
			}
			else
			{
				if (distanceIdx > size)
				{
					int swamNum = dArr.back();
					dArr.pop_back();
					dArr.push_front(swamNum);
					result++;
				}
				else
				{
					int swamNum = dArr.front();
					dArr.pop_front();
					dArr.push_back(swamNum);
					result++;
				}
			}

		}
	}
	cout << result;
}