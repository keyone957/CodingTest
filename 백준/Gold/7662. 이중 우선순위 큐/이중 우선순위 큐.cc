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
using namespace std;
priority_queue<int> downArr;
priority_queue<int, vector<int>, greater<int>> upArr;
map<int, int> cnt; // 값별 개수 카운트
void clearArr()
{
    while (!downArr.empty())
    {
        downArr.pop();
    }
    while (!upArr.empty())
    {
        upArr.pop();
    }
    cnt.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    


    int T;
    cin >> T;
    while (T--)
    {
        clearArr();
        int K;
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            char input;
            int num;
            cin >> input >> num;
            if (input == 'I')
            {
                downArr.push(num);
                upArr.push(num);
                cnt[num]++; // 값 개수 증가
            }
            else if(input=='D')
            {
                if (num == 1) // 최댓값 삭제
                {
                    while (!downArr.empty() && cnt[downArr.top()] == 0)
                    {
                        downArr.pop();
                    }
                    if (!downArr.empty())
                    {
                        cnt[downArr.top()]--;
                        downArr.pop();
                    }
                }
                else if (num == -1) // 최솟값 삭제
                {
                    while (!upArr.empty() && cnt[upArr.top()] == 0)
                    {
                        upArr.pop();
                    }
                    if (!upArr.empty())
                    {
                        cnt[upArr.top()]--;
                        upArr.pop();
                    }
                }
            }
        }
        // 마지막 정리
        while (!downArr.empty() && cnt[downArr.top()] == 0)
            downArr.pop();
        while (!upArr.empty() && cnt[upArr.top()] == 0)
            upArr.pop();

        if (downArr.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << downArr.top() << " " << upArr.top() << "\n";
        }
    }
}