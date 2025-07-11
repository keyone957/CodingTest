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
vector<vector<int>> linkedList;
vector<bool>visited;
//bool isAnswer;
int N, M;
void DFS(int startNode,int answerCount)
{
    if (answerCount == 5)
    {
        cout << 1 << '\n';
        //isAnswer = true; 
        exit(0);
    }
    visited[startNode] = true;
    for (int i = 0; i < linkedList[startNode].size(); i++) 
    {
        int next = linkedList[startNode][i];
        if (!visited[next]) 
        {
            DFS(next, answerCount + 1);
        }
    }
    visited[startNode] = false; // 백트래킹
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    linkedList.resize(N);
    visited.resize(N);
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedList[start].push_back(end);
        linkedList[end].push_back(start);
    }
    for (int i = 0; i < N; i++)
    {
        fill(visited.begin(), visited.end(), false);
        DFS(i,1);
   
    }
        cout << 0;
}