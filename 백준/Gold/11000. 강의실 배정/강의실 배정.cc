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
수업 시작 끝
최소의 강의실을 사용해서 모든 수업을 가능하게 해야함.
1 3 
2 4
3 5
---
1강의실 1 3 , 3 5 
2강의실 2 4 
해서 최소로 2개

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;//오름차순
    vector<pair<int, int>> input;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        input.push_back({ start,end });
    }
    sort(input.begin(), input.end());
    int maxroom = -1;
    for (int i = 0; i < n; i++)
    {
        int startTime=input[i].first;
        int endTime = input[i].second;

        if (!pq.empty()&&pq.top()<=startTime)
        {
            pq.pop();
        }
        pq.push(endTime);
        maxroom = max(maxroom, (int)pq.size());
        
    }
    cout << maxroom;
}