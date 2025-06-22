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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W;
    cin >> H >> W;
    vector<int> water;
    for (int i = 0; i < W; i++)
    {
        int input;
        cin >> input;
        water.push_back(input);
    }
    vector<int> rain(W);
    rain[0] = 0;
    rain[W-1] = 0;
    vector<int> leftMax(W);
    vector<int> rightMax(W);
    leftMax[0] = water[0];
    rightMax[W - 1] = water[W - 1];

    for (int i = 1; i < W;i++)
    {
        leftMax[i] = max(leftMax[i - 1], water[i]);
    }
    for (int i = W-2; i >=0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], water[i]);
    }
    for (int i = 1; i < W - 1; i++)
    {
        int curRain=min(leftMax[i], rightMax[i]) - water[i];
        if (curRain >= 0)
        {
            rain[i] = curRain;
        }
        else
        {
            rain[i] = 0;
        }
    }
    int answer = 0;
    for (int i = 0; i < rain.size(); i++)
    {
        answer += rain[i];
    }
    cout << answer;
}