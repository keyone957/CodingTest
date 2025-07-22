#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, n;
    cin >> k >> n;
    vector<long long> arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    long long left = 1;
    long long right = *max_element(arr.begin(), arr.end());
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long line = 0;
        for (int i = 0; i < k; i++)
            line += arr[i] / mid;

        if (line < n)
            right = mid - 1;
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }
    cout << answer << '\n';
}
