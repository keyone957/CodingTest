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
char board[201][201];
char temp[201][201];
int R, C, N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1,  0 };
void print()//1일때는 그대로 출력
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}
void print1()//짝수일때
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << 'O';
        }
        cout << "\n";
    }
}
void allBomb()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] = 'O';
        }
    }
}
void bomb3(char tempBoard[201][201])// 폭탄으로 바꾸기
{
    allBomb();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (tempBoard[i][j] == 'O')
            {
                board[i][j] = '.';
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
                    board[ny][nx] = '.';
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = input[j];

        }
    }
    if (N == 1)
    {
        print();
        return 0;
    }
    else if (N % 2 == 0)
    {
        print1();
    }
    else if (N % 4 == 3)//3초일때?
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                temp[i][j] = board[i][j];
        bomb3(temp);
        print();
    }
    else if (N % 4 == 1)//5초일때?
    {
        for (int a = 0; a < 2; a++)
        {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    temp[i][j] = board[i][j];
            bomb3(temp);
        }
    
        print();
    }
}