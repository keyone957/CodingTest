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
int r, c;
char arr[51][51];
int dist[51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int endX = 0;
    int endY = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    queue<pair<int, int>> waterQ;
    for (int i = 0; i < r; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < c; j++)
        {
            arr[i][j] = input[j];
            if (input[j] == 'S')
            {
                q.push({ i,j });
                dist[i][j] = 0;
            }
            if (input[j] == 'D')
            {
                endX = j;
                endY = i;
            }
            if (input[j] == '*')
            {
                waterQ.push({ i,j });
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int waterQSize = waterQ.size();
        while (waterQSize--)
        {
            pair<int, int> cur = waterQ.front();
            waterQ.pop();
            int y = cur.first;
            int x = cur.second;
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (nx < 0 || ny < 0 || ny >= r || nx >= c) continue;
                if (arr[ny][nx] == '.')
                {
                    arr[ny][nx] = '*';
                    waterQ.push({ ny,nx });
                }
            }
        }
        int qSize = q.size();
        while (qSize--)
        {
            pair<int, int> cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;

            if (y == endY && x == endX)
            {
                cout << dist[y][x] << "\n";
                return 0;
            }

            for (int i = 0; i < 4; i++)
            {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if (nx < 0 || ny < 0 || ny >= r || nx >= c) continue;
                if (dist[ny][nx] != -1)continue;
                if (arr[ny][nx] == '.' || arr[ny][nx] == 'D')
                {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({ ny,nx });
                }
            }
        }

    }
    cout << "KAKTUS\n";
    return 0;
}