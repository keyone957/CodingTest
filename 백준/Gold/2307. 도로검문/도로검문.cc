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
vector<pair<int,int>> linkedList[1001];
int path[1001];
vector<int> minDist;
int INF = 1e9;
/*
용의자는 항상 1번부터 시작. N번 지점까지 가고. 이제 경창은 적절한 도로를 선택해 용의자들의 탈출시간을 최대한 지연
어떤도로 막으면 -1로 도시 탈출 못할 수도 있음. 이때는 -1

하나의 도로를 막음으로써 최대한 지연시킬수 있는 시간수. 

일단 아무것도 삭제안했을때의 경로를 저장해 놓고 그 최단 경로의 간선을 하나하나 삭제하면서
거리 갱신하면서 확인하는 방법?

*/
int n,m;
void bfs(int startNode)
{
    
    priority_queue<pair<int, int>> pq;
    minDist[startNode] = 0;
    pq.push({ 0,startNode });
    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curNodeCost = -pq.top().first;
        pq.pop();
        if (minDist[curNode] < curNodeCost)continue;
        for (int i = 0; i < linkedList[curNode].size(); i++)
        {
            int cost = curNodeCost+linkedList[curNode][i].second;
            if (cost < minDist[linkedList[curNode][i].first])
            {
                minDist[linkedList[curNode][i].first] = cost;
                pq.push(make_pair(-cost, linkedList[curNode][i].first));
                path[linkedList[curNode][i].first] = curNode;
            }
        }
    }
}
void bfs2(int startNode,int eStart,int eEnd)
{
    priority_queue<pair<int, int>> pq;
    minDist[startNode] = 0;
    pq.push({ 0,startNode });
    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curNodeCost = -pq.top().first;
        pq.pop();
        if (minDist[curNode] < curNodeCost)continue;
        for (int i = 0; i < linkedList[curNode].size(); i++)
        {
            int cost = curNodeCost + linkedList[curNode][i].second;
            if ((curNode == eStart && linkedList[curNode][i].first == eEnd)||
                (curNode == eEnd && linkedList[curNode][i].first== eStart)) continue;
            if (cost < minDist[linkedList[curNode][i].first])
            {
                minDist[linkedList[curNode][i].first] = cost;
                pq.push(make_pair(-cost, linkedList[curNode][i].first));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    minDist.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        linkedList[start].push_back({ end,cost });
        linkedList[end].push_back({ start,cost });
    }
    fill(minDist.begin(), minDist.end(), INF);
    bfs(1);
    int thiefDist;

    thiefDist = minDist[n];

    int answer = -1;
    int endNode = n;
    while (endNode != 1) {
        int startNode = path[endNode]; // endNode의 부모(직전 방문 노드)

        // (startNode <-> endNode) 간선을 끊고 돌려봄
        fill(minDist.begin(), minDist.end(), INF);
        bfs2(1, startNode, endNode);

        if (minDist[n] == INF) {
            cout << -1;
            return 0;
        }

        answer = max(answer, minDist[n] - thiefDist);

        // 다음 단계로 이동 (거꾸로 올라감)
        endNode = startNode;
    }
    
    cout << answer;
}