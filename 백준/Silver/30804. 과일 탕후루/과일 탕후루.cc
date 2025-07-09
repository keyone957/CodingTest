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
    int count;
    cin >> count;
    vector<int> arr(count);
    int fruitType[10] = {0};
    int typeCnt = 0;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int end = 0;
    int answer = 0;
    while (end<count)
    {
        if (fruitType[arr[end]] == 0)
        {
            typeCnt++;
        }//만일 end의 typecnt가 0이면 갱신
        fruitType[arr[end]]++;
        end++;
        //일단 end인덱스를 ++

        while (typeCnt > 2)
        {
            fruitType[arr[start]]--;
            if (fruitType[arr[start]] == 0)
            {
                typeCnt--;
            }
            start++;
        }
        answer = max(answer, end - start);
    }
    cout << answer;
}
