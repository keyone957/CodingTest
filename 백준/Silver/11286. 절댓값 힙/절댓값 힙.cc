#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <functional>
struct compare
{
	bool operator()(int a, int b)
	{
		int absA = abs(a);
		int absB = abs(b);
		if (absA == absB)
		{
			return a > b;
		}//만약에 두개의 절댓값이 같다면 음수 우선으로 정렬되게 함
		return absA > absB;//우선 절댓값 기준으로 정렬 되도록 하되
	}
};//==> 핵심 
// 우선순위 큐를 사용하여 사용자 정의 조건 구조체를 만들어줌.
//
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//priority_queue<int> qArr;  // - >  priority_queue<int, vector<int>, less<int>> pq;
	//가장 큰값이 top에 있음
	priority_queue<int, vector<int>, compare> qArr;
	//가장 작은 값이 top에 있음
	vector<int>resultArr;
	int count;
	cin >> count;	
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >>input;
		if (input == 0)
		{
			if (qArr.empty())
			{
				resultArr.push_back(0);
			}
			else
			{
				resultArr.push_back(qArr.top());
				qArr.pop();
			}
		}
		else
		{
			qArr.push(input);
		}
	}
	for (int i = 0; i < resultArr.size(); i++)
	{
		cout << resultArr[i] << "\n";
	}
}