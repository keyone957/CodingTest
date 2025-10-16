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
int INF = 1e9; //max Int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    12(적어도 몇명을 늘려야하는지) 2 (도시 수)
    3(비용) 5(얻는 고객수)
    1(비용) 1(얻는 고객수)

    answer =8
    */
    int c, n;
    cin >> c >> n;
    vector<int> cost;
    cost.resize(n);
    vector<int> person;
    person.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i] >> person[i];
    }
    vector<int> dp(c+101, INF);//i명을 얻기 위해 투자해야하는 돈의 최소비용
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = person[i]; j< c + 101; j++)
        {
            dp[j] = min(dp[j], dp[j - person[i]] + cost[i]);
        }
    }

    int answer = *min_element(dp.begin() + c, dp.end());
    cout << answer;


}