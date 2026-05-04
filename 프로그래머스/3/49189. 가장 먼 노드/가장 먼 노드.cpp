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

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int cost[20001]={0};
    vector<int> linkedList[500001];
    
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];

        linkedList[a].push_back(b);
        linkedList[b].push_back(a);
    }   
    queue<int> q;
    q.push(1);
    cost[1]=1;
    while(!q.empty())
    {
        int cur=q.front(); q.pop();
    
        for(int i=0;i<linkedList[cur].size();i++)
        {
            int next=linkedList[cur][i];
            if(cost[next]==0)
            {
               cost[next]=cost[cur]+1;
               q.push(next);
                
            }
        }
    }
    int maxCost=-1;
    for(int i=1;i<=n;i++)
    {
        maxCost=max(maxCost,cost[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(cost[i]==maxCost)
        {
            answer++;
        }
    }
    return answer;
}