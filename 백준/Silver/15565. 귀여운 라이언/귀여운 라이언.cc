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
using namespace std;
int n, k;
int input[1000001];
/*
라이언 1
어피치 2
k개 이상의 라이언 인형을 포함하는 가장 작은 연속된 인형들의 집합 크기
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int leftIdx=0;
    int rightIdx=0;
    int count=0;
    int answer = 1e9;
    for (int right = 0; right < n; right++)
    {
        if (input[right] == 1)
        {
            count++;
        }
        while (count >= k)
        {
            answer = min(answer, right - leftIdx + 1);
            if (input[leftIdx] == 1) count--;
            leftIdx++;

        }
    }
    if (answer != 1e9)
    {
        cout << answer;
    }
    else
    {
        cout << -1;
    }
}