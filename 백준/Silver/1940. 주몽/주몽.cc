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
int n, m;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = n-1;
    int answer = 0;
    while (left < right)
    {
        int leftV = arr[left];
        int rightV = arr[right];
        int sum = leftV + rightV;

        if (sum == m)
        {
            answer++;
            right--;
            left++;
        }
        else if (sum<m)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << answer;
}