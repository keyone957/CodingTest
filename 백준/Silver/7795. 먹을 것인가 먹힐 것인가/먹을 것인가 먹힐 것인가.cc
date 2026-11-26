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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        vector<int> a;
        vector<int> b;
        int aP=0;
        int bP=0;
        
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < m; i++)
        {
            int input;
            cin >> input;
            b.push_back(input);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int answer = 0;
        while (aP < n && bP < m)
        {
            if (a[aP] > b[bP])
            {
                answer = answer + (n - aP);
                bP++;
            }
            else
            {
                aP++;
            }
        }
        cout << answer<<'\n';
    }

}