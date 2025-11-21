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

n명의 플레이어 있음.
m개의 영운은 구린영웅
다 던지기로함
트롤픽을 더 적게 한 팀이 이김
각 팀원들이 고르고 싶어하는 트롤픽의 리스트가 주어짐.
그마를 찍을 수 있는지 알아봦
비기면 점수 x 다 던짐

최대한 많은 팀원들이 즐겜.

input
5 4 5 3
ㅡㅡ
1 1
2 2
3 3
4 4
5 2
ㅡㅡ
1 1
2 1
3 1
ㅡㅡ

*/
int n, m, k1, k2;
vector<int> linkedList[301];
vector<int> linkedList1[301];
int ocuppied[301];
bool visited[301];
int myteam = 0;
int otherTeam = 0;
bool dfs(int startNode)
{
    for (int i = 0; i < linkedList[startNode].size(); i++)
    {
        int node = linkedList[startNode][i];
        if (visited[node]) continue;
        visited[node] = true;
        if (ocuppied[node] == 0 || dfs(ocuppied[node]))
        {
            ocuppied[node] = startNode;
            return true;
        }
    }
    return false;
}
bool dfs1(int startNode)
{
    for (int i = 0; i < linkedList1[startNode].size(); i++)
    {
        int node = linkedList1[startNode][i];
        if (visited[node]) continue;
        visited[node] = true;
        if (ocuppied[node] == 0 || dfs1(ocuppied[node]))
        {
            ocuppied[node] = startNode;
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k1 >> k2;
    

    for (int i = 0; i < k1; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedList[start].push_back(end);
    }
    fill(ocuppied, ocuppied + 301, 0);
    for (int i = 1; i <= n; i++)
    {
        fill(visited, visited + 305, false);
        if (dfs(i))
        {
            myteam++;
        }
    }

    for (int i = 0; i < k2; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedList1[start].push_back(end);
    }
    fill(ocuppied, ocuppied + 305, 0);
    for (int i = 1; i <= n; i++)
    {
        fill(visited, visited + 305, false);
        if (dfs1(i))
        {
            otherTeam++;
        }
    }
    if (myteam < otherTeam)
    {
        cout << "네 다음 힐딱이";
    }
    else
    {
        cout << "그만 알아보자";
    }

}