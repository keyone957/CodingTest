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
	if (a == M)//M개 까지의 수를 택했으면
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';// 이제 수열을 완성한것 이므로 출력
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!isUsed[i])//사용되지 않은 수라면
		{
			arr[a] = i;//현재 보고 있는 수를 i로 정함
			isUsed[i] = 1;//그 수는 사용된 수이므로 true로 변경해줌
			func(a + 1);//다음 순서에 들어갈 수를 정하러 한단계 더 내려감.
			isUsed[i] = 0;//이제 a 번째 수를 정한 모든 경우에 대해 다 확인 했으니 
			//i를 사용하지 않은 상태로 변경해줘야함

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	func(0);
}