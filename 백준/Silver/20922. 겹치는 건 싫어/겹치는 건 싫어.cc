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
    int N, K;
    cin >> N >> K;
    int left = 0;
    int right = 0;
    int answer = 0;
    vector<int> arr;
    int countArr[100001] = {0};
    arr.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    while (right<N)
    {
        if (countArr[arr[right]] < K)
        {
            countArr[arr[right]]++;
            answer = max(answer, right - left + 1);
            right++;
        }
        else
        {
            countArr[arr[left]]--;
            left++;
        }
    }
    cout << answer;

}