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
int n;
priority_queue<int> smallPq;//중간값 보다 작은 
priority_queue<int,vector<int>,greater<int>> bigPq;//중간값 보다 큰 
int main()
{
    /*
    짝수개 이면 중간에 있는 두수 중에서 작은 수
    우선순위 큐?
    작은 pq 요소 갯수가 더 적거나 같으면 작은거에서 top출력
    큰 pq가 더 많으면 bigpq에서 top출력
    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int startNum;
    cin >> startNum;
    smallPq.push(startNum);

    int curSum = 0;
    curSum += startNum;
    cout << startNum << '\n';

    for (int i = 1; i < n; i++)
    {
        int input;
        cin >> input;
       /* curSum += input;
        int midNum = curSum / 2;
        if (input <= midNum)
        {
            smallPq.push(input);
        }
        else
        {
            bigPq.push(input);
        }
        int smallCnt = smallPq.size();
        int bigPqCnt = bigPq.size();
        if (smallCnt >= bigPqCnt)
        {
            cout << smallPq.top() << '\n';
        }
        else
        {
            cout << bigPq.top() << '\n';
        }*/
        if (input <= smallPq.top())
            smallPq.push(input);
        else
            bigPq.push(input);

        // ② 두 힙 균형 맞추기
        if (smallPq.size() > bigPq.size() + 1) {
            bigPq.push(smallPq.top());
            smallPq.pop();
        }
        else if (bigPq.size() > smallPq.size()) {
            smallPq.push(bigPq.top());
            bigPq.pop();
        }
        cout << smallPq.top() << '\n';
    }

}