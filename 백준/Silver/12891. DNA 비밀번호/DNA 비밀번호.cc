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

int S, P;
string passWord;
int passWordCnt[4]; // 입력 받은 각 문자들의 조건 횟수
int inputArrCnt[4]; // 현재 구간에서 각 문자의 개수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> P;
    cin >> passWord;
    for (int i = 0; i < 4; i++)
        cin >> passWordCnt[i];

    // 처음 P개 구간의 문자 세기
    for (int i = 0; i < P; i++) {
        if (passWord[i] == 'A') inputArrCnt[0]++;
        else if (passWord[i] == 'C') inputArrCnt[1]++;
        else if (passWord[i] == 'G') inputArrCnt[2]++;
        else if (passWord[i] == 'T') inputArrCnt[3]++;
    }

    int left = 0;
    int right = P - 1;
    int curState = 0;
    int answer = 0;

    while (curState < S - P + 1)
    {
        // 조건 만족 체크
        bool answerTrigger = true;
        for (int i = 0; i < 4; i++)
        {
            if (inputArrCnt[i] < passWordCnt[i])
            {
                answerTrigger = false;
                break;
            }
        }
        if (answerTrigger)
            answer++;

        // 마지막 구간이면 종료 (right+1이 S가 됨)
        if (curState == S - P) break;

        // 왼쪽 문자 빼기
        if (passWord[left] == 'A') inputArrCnt[0]--;
        else if (passWord[left] == 'C') inputArrCnt[1]--;
        else if (passWord[left] == 'G') inputArrCnt[2]--;
        else if (passWord[left] == 'T') inputArrCnt[3]--;

        left++;
        right++;

        // 오른쪽 문자 더하기
        if (passWord[right] == 'A') inputArrCnt[0]++;
        else if (passWord[right] == 'C') inputArrCnt[1]++;
        else if (passWord[right] == 'G') inputArrCnt[2]++;
        else if (passWord[right] == 'T') inputArrCnt[3]++;

        curState++;
    }

    cout << answer;
}
