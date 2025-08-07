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
    int n, m;
    cin >> n >> m;
    vector<int>input;
    input.resize(n);
    int sum=0;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        sum += input[i];
    }
    //int left=input[n-1];
    int left = *max_element(input.begin(), input.end());
    int answer = 0;

    while (left <= sum)
    {
        int mid = (left + sum) / 2;
        int count=1;
        int partSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (partSum +input[i]> mid)
                //더했을때 한 블루레이의 크기가 넘는지 안넘는지 체크
            {
                partSum = 0;
                count++;
                //넘었을때는 이제 partSum을 초기화 해주고
                //블루레이 개수 증가
            }
            partSum += input[i];
        }
        if (count <= m)
        {
            answer = mid;
            sum= mid - 1;
        }
        else
        {
            left = mid + 1;
        }

    }
    cout << answer;

}