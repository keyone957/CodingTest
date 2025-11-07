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
int dp[1001];
//i번째 까지의 값을 포함했을 때 최대 값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = input[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] < input[i])
            {
                dp[i] = max(dp[i],dp[j]+input[i]);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp[i]);
    }
    cout << answer;
}