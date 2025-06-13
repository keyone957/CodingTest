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
    int N, M;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        A.push_back(input);
    }
    sort(A.begin(), A.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        int start = 0;
        int end = N - 1;
        bool isFound = false;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (A[mid] < input)
            {
                start = mid + 1;
            }
            else if (A[mid] > input)
            {
                end = mid - 1;
            }
            else
            {
                isFound = true;
                break;
            }
        }
        if (isFound)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}