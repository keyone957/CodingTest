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
int N, M;
int arr[10];
int isUsed[10];

void func(int a)//현재 a개까지 수를 택함
{
	if (a == N)//M개 까지의 수를 택했으면
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << ' ';// 이제 수열을 완성한것 이므로 출력
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!isUsed[i])
		{
			arr[a] = i;
			isUsed[i] = 1;
			func(a + 1);
			isUsed[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	func(0);
}