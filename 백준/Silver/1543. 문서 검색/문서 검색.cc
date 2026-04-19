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
string check;
string findString;
int answer;
int main()
{
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin, check);
    getline(cin, findString);
    int idx= 0;
    while (idx <= (int)check.size() - (int)findString.size())
    {
        /*if (check[idx] == findString[0])
        {
           check.substr(idx,findString.size())
        }*/
        if (check.substr(idx, findString.size()) == findString)
        {
            answer++;
            idx += findString.size();
        }
        else
        {
            idx++;
        }
    }
    cout << answer;
}