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
/*
먼저 갱신
x까지. 
for문으로 n-x+1 까지 돌리는데

i=1부터

curSum=cursum-inputarr[i-1]+inputarr[i+x-1];

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> input;
    int n, x;
    cin >> n >> x;
    //x일동안 가장 많이 들어온 방문자 수
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }
    int curSum=0;
    int answerCount = 1;
    int maxSum=0;

    for (int i = 0; i < x; i++)
    {
        curSum += input[i];
    }
    maxSum = curSum;
    for (int i = 1; i < n - x + 1; i++)
    {
        curSum = curSum - input[i - 1] + input[i + x - 1];
        if (curSum == maxSum)// 그 조회수가 같을 수도 있으니 같을때는 ++
        {
            answerCount++;
        }
        else if(curSum>maxSum)// 더 많은 조회수가 있다면 이제 새로운 값으로 갱신
        {
            maxSum = curSum;
            answerCount=1;
        }
    }
    if (maxSum == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << maxSum << '\n'<<answerCount;
    }
}