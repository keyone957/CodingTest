#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
	//투포인터 문제
	//이중 for문을 돌려서 계속 더하고 답을 체크하면 시간 복잡도가 O(N^2)
	//but 투포인터 사용하여 문제 풀면 O(N)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	int leftIdx = 1;
	int rightIdx = 1;
	int answer = 0;
	int arr[10001] = {};

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	while (rightIdx != n+1)
	{
		int sum = 0;
		for (int i = leftIdx; i <= rightIdx; i++)
		{
			sum += arr[i];
		}
		if (sum == m)
		{
			rightIdx++;
			answer++;
		}
		else if (sum > m)
		{
			leftIdx++;
		}
		else if (sum < m)
		{
			rightIdx++;
		}

	}
	cout << answer;
}