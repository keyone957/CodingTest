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
//long  board[1501][1501];
struct cmp {
	bool operator()(long a, long b)
	{
		return a > b;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<long , vector <  long > , cmp/*greater< long>*/> pq;
	int N;
	cin >> N;
	/*for(int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long input;
			cin >> input;
			board[i][j] = input;
			pq.push(board[i][j]);
		}
	}*/
	for (int i = 0; i < N * N; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
		if (pq.size() > N) {
			pq.pop(); // 항상 크기를 N으로 제한
		}
	}
	int answer;
	/*for (int i = 0; i < N-1; i++)
	{
		pq.pop();
	}*/
	cout << pq.top()<<"\n";
	/* 
	*/
}