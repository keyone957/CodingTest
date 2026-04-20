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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
#include<cstring>
using namespace std;
/*

입력 
2 
10
15

출력
20

1개로만 버틸때
-> 15가 최대

만약 2개로 버틸때
로프 a b 에 10 10 씩 걸림
최대는 20

30키로 든다 치면
10 15 는 15 15로 들어야 하는데 a가 15를 못버팀
따라서 정답 20

*/
int n;
vector<int>arr;
int answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int weight = arr[i] * (n - i);
        answer = max(weight, answer);
    }
    cout << answer;
}