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
int n;
string result;
void dfs(int cnt)
{
    if (cnt == n)
    {
        cout << result;
        exit(0);
    }
    for (int i = 1; i <= 3; i++)
    {
        result += '0' + i;

        int L = result.size();
        bool isBad = false;

        for (int k = 1; k <= L / 2; k++)
        {
            bool same = true;

            for (int t = 0; t < k; t++)
            {
                if (result[L - 1 - t] != result[L - 1 - k - t])
                {
                    same = false;
                    break;
                }
            }

            if (same)
            {
                isBad = true;
                break;
            }
        }

        if (!isBad)
            dfs(cnt + 1);

        result.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dfs(0);
}