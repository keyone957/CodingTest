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
long long x, y;//x y 는 10억보다 작거나 같음
int w, s;
/**
    oneBlockTime<=crossTime
    onBlockTime -> 직선이동
    crossTime -> 대각선 이동
    이때는 굳이 대각선으로 이동하는 것보다 모두 그냥 모두 한칸씩 이동하는게 더 빠름
    0 0 에서 x y 까지.
    남은 거리를 계산해서 가로질러갈지 or 직선으로 갈지?


- 경우의 수
1. 직선 이동만 하는 경우 w
2. 최대한 대각선으로가고 남은 거리만 평행이동 s or w
       min(x,y) -> 대각선으로만 이동은 x+1 y+1
     즉 대각선으로만 이동하는 횟수는 목표 지점의 x또는 y에서 작은 값.
     그 다음에 남은 거리를 직선이동으로 계산
3. 대각선으로만 이동 s
 

대각선 *2 가 직선 1보다 비용이 적은가?

대각선 이동 x+1 y+1

직선 이동은 x+1 y / x y+1.... 
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> x >> y >> w >> s;
    long long first,second,third;
    first = (x + y) * w;//일반 직선으로만 이동
    
    second = min(x, y) * s+abs(x-y)*w;
    //이제 x+1 y+1 로 먼저 최대한 대각선으로만 간 거리 + 남은 거리 (|x-y|*s) 계산

    if ((x + y) % 2 == 0)//근데 이제 이 마지막에 남은 거리에 따라서 직선 이동 또는 직선 + 대각선 이동을 비교를 해서 최소 거리로 갱신함.
    {
        third = max(x, y) * s;
    }
    else//직선 이동 후에 대각선 이동
    {
        third = (max(x, y) - 1  )*s+ w;
    }


    cout << min({ first,second,third });
}