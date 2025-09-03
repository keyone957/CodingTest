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
int N, M;
int startPoint, endPoint;
vector<pair<int, int>> cityArr[100001];
vector<long long >minDist;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    minDist.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        cityArr[start].push_back(make_pair(end, cost));
    }
    cin >> startPoint >> endPoint;
    fill(minDist.begin(), minDist.end(), 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,startPoint });
    minDist[startPoint] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (minDist[cur] < cost)continue;

        for (int i = 0; i < cityArr[cur].size(); i++)
        {
            int nextNode = cityArr[cur][i].first;
            int curCost = cityArr[cur][i].second;
            long long dist = cost + curCost;
            if (dist < minDist[nextNode])
            {
                minDist[nextNode] = dist;
                pq.push(make_pair(dist, nextNode));
            }
        }
    }
    cout << minDist[endPoint];


}