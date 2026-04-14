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
int n, k;
int arr[200001];
int countArr[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int right = 0;
    int count = 0;
    while (right < n)
    {
      
        if (countArr[arr[right]] < k)
        {
            countArr[arr[right]]++;
            count = max(count, right - left + 1);
            right++;
        }
        else
        {
            countArr[arr[left]]--;
            left++;
        }

    }
    cout << count;
}