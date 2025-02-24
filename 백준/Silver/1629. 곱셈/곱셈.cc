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
#include <cmath>
using namespace std;
long long powCustom(int a, int b, int c)
{
	if (b == 1) return a % c;
	long long val = powCustom(a, b / 2, c);// 계속 반씩 줄여가면서 값을 줄여간다.
	val = val * val % c;//한번에 다 구해서 나머지를 구하는것이 아닌 A * A 한번 할때마다 나머지를 RETURN해줌.==>그림설명있음
	if (b % 2 == 0) return val;
	return val * a % c;//홀수 일때 ex) 2^5 == 2^4*2 == 2^2*2^2*2이므로 마지막에 a하나 곱해주고 나머지 구해줘야함
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << powCustom(a, b, c);
}