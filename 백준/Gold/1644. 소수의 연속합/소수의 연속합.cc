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
	int N;
	cin >> N;

	vector<int> sosu;
	/*for (int i = 2; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 1)
		{
			sosu.push_back(i);
		}
	}*/
	vector<bool> isPrime(N + 1, true);
	isPrime[0] = isPrime[1] = false;

	// 에라토스테네스의 체
	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	}

	// 소수 리스트 만들기
	//vector<int> primes;
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			sosu.push_back(i);
	}
	//소수 구하기
	int size = sosu.size();
	int startIdx=0;
	int endIdx=0;
	int answer = 0;
	vector<int> sumArr(size+1,0);
	for (int i = 1; i <= size; i++)
	{
		sumArr[i] = sumArr[i - 1] + sosu[i - 1];
	}
	while (startIdx<=endIdx&&endIdx<=size)
	{
		int sum=sumArr[endIdx] - sumArr[startIdx];
		if (sum == N)
		{
			startIdx++;
			//endIdx++;
			answer++;
		}
		else if (sum > N)
		{
			startIdx++;
		}
		else if (sum < N)
		{
			endIdx++;
		}
	}
	cout << answer;


}