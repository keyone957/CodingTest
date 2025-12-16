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
출력 -> 정점 u를 루트로 하는 서브트리에 속한 정점의 수
n 트리 정점
r 루트 번호
q 쿼리 수

n-1에 거쳐 u v 형태로 간선 정보

q수에 따라서 문제에 설명한 u가 하나씩 주어짐?
q줄에 걸쳐 각 쿼리의 답을 정수 하나로 출력함
*/
int n, r, q;
vector<int> adj[100001];
int countArr[100001];
bool visited[100001];
void dfs(int curNode)
{
    countArr[curNode] = 1;
    visited[curNode] = true;
    for (int i = 0; i < adj[curNode].size(); i++)
    {
        int nextNode = adj[curNode][i];
        if(visited[nextNode]) continue;
        dfs(nextNode);
        countArr[curNode] += countArr[nextNode];
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> q;
   
    for (int i = 0; i < n - 1; i++)
    {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    dfs(r);
    for (int i = 0; i < q; i++)
    {
        int node;
        cin >> node;
        cout << countArr[node] << '\n';
    }

}