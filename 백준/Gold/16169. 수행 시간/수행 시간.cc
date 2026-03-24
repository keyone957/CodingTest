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
int n;
vector<int> adj[101];
int cost[101];
int dp[101];// 현재 이 컴퓨터까지 왔을때 최대 완료 시간
/*
계급은 1부터 
각 컴퓨터 전송시간은 i->j라 하면
(i -j)^2

한단계 낮은 컴퓨터에게 정보를 전달 받아야만 동작을 시작할 수 있음
이때 이 동작 속도 만큼의 시간이 소요 

계급이 c인 컴퓨터가 동작을 마치면 c+1 계급을 가진 모든 컴퓨터에 정보를 전달 후 종료

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int maxGrade = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int grade, time;
        cin >> grade >> time;
        adj[grade].push_back(i);
        cost[i] = time;
        maxGrade = max(grade, maxGrade);
    }
    for (int i = 0; i < adj[1].size(); i++)
    {
        int node = adj[1][i];
        dp[node] =cost[node];
    }
    //cout << maxGrade;
    //일단 먼저 맨 처음에 가장 낮은 계급인 1을 가지고 있는 노드의 dp테이블을 초기화해줌


    for (int i = 2; i <= maxGrade; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)//현재 계급 노드들
        {
            int node = adj[i][j];
            int maxVal = -1;
            for (int k = 0; k < adj[i - 1].size(); k++)//이전 계급 노드들
            {
                int prev = adj[i-1][k];
                int val = dp[prev] + pow((prev - node), 2);
                maxVal = max(maxVal, val);
            }
            dp[node] = maxVal + cost[node];
        }
    }
    int answer = 0;
    //cout << dp[maxGrade];
    for (int i = 0; i < adj[maxGrade].size(); i++)
    {
        int node = adj[maxGrade][i];
        answer = max(answer, dp[node]);
    }
    cout << answer;
}