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
vector<int> arr;
int sumArr[100001];
/*
합이 s이상이 되는것 중 가장 짧은 것의 길이를 구하는것
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int leftIdx = 0;
    int rightIdx = 0;
    int sum = 0;
    int answer = 1e9f;
    while (true)
    {
        if (sum < s)//현재 누적합이 s보다 작으면 오른쪽으로 인덱스 이동해서 더해줌
        {
            if (rightIdx == n) break;
            sum += arr[rightIdx];
            rightIdx++;
        }
        else// 더 크면최소값들 갱신해보기
        {
            answer = min(answer, rightIdx - leftIdx);

            sum -= arr[leftIdx];
            leftIdx++;
        }
    }
    if (answer == 1e9)
    {
        cout << 0;
    }
    else
    {
        cout << answer;
    }
}