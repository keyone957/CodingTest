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
int m,answer;
int rest[6] = { 500,100,50,10,5,1 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    int restM = 1000 - m;
    int i=0;
    while (restM)
    {
        int check = restM - rest[i];
        if (check >= 0)
        {
            restM = check;
            answer++;
        }
        else
        {
            i++;
        }
    }
    cout << answer;

}