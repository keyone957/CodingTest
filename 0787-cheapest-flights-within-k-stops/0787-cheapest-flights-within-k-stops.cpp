/*
k번 다익스트라 사용하면될것 같음 그대신에 이제 횟수를 같이 저장하면서 가야할듯?
*/
class Solution {
vector<pair<int,int>> adj[101];
int cost[101][101];
/*
i번 노드로 들어왔을때
j번 방문했다 치면 
그때의 최소비용
*/
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int answer=0;
        for(int i=0;i<flights.size();i++)
        {
            int start=flights[i][0];
            int end=flights[i][1];
            int cost=flights[i][2];
            adj[start].push_back({end,cost});
        }
        // int stop=0;
        fill(cost[0],cost[101],1e9);
        queue<pair<int,int>> q;
        q.push({src,0});
        cost[src][0]=0;
        while(!q.empty())
        {
            pair<int,int> cur=q.front();
            q.pop();
            int curNode=cur.first;
            int stop=cur.second;
            for(int i=0;i<adj[cur.first].size();i++)
            {
                int nextNode=adj[curNode][i].first;
                int nextCost=adj[curNode][i].second;
                if (stop <= k && cost[curNode][stop] + nextCost < cost[nextNode][stop + 1])
                {
                    cost[nextNode][stop + 1] = cost[curNode][stop] + nextCost; 
                    q.push({nextNode, stop + 1});
                }
            }

        }
        int min_price = 1e9;
    for (int i = 0; i <= k + 1; i++) {
    if (cost[dst][i] < min_price) {
        min_price = cost[dst][i];
    }
}
answer = (min_price == 1e9) ? -1 : min_price;
        return answer;  
    }
};