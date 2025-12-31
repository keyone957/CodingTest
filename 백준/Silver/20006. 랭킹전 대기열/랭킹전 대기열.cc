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
1. 매칭 불가 -> 방생성. **처음 입장한 플레이어 기준**으로 -10 +10
2. 입장 가능 -> 정원찰때까지 대기
    - 이때 입장간으방이 여러개면 먼저 생성된 방에 입장
3. 방 다 차면 게임 시작

p : 플레이어 수 
n : 플레이어 닉넴
i : 플레이어 레벨
m : 방한개의 정원

--> 최종적으로 만들어진 방 상태 입장 플레어들 출력
*/

struct Player
{
    int level;
    string name;
};
struct Room
{
    int roomLevel;
    vector<Player> roomPlayerInfo;
};
int p, m;
vector<Room> curRoomInfo;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> p >> m;
    for (int i = 0; i < p; i++)
    {
        int level;
        string name;
        cin >> level >> name;
        Player player;
        player.level = level;
        player.name = name;
        int roomCnt = curRoomInfo.size();
        if (roomCnt == 0)
        {
            Room newRoom;
            newRoom.roomLevel = level;
            newRoom.roomPlayerInfo.push_back(player);
            curRoomInfo.push_back(newRoom);
        }
        else
        {
            int entered = false;
            for (int j = 0; j < roomCnt; j++)
            {
                if (abs(curRoomInfo[j].roomLevel - player.level) <= 10&&curRoomInfo[j].roomPlayerInfo.size()<m)
                {
                    curRoomInfo[j].roomPlayerInfo.push_back(player);
                    entered = true;
                    break;
                }
            }
            if (!entered)
            {
                Room newRoom;
                newRoom.roomLevel = level;
                newRoom.roomPlayerInfo.push_back(player);
                curRoomInfo.push_back(newRoom);
            }
        }
    }
    for (auto& room : curRoomInfo)
    {
        // 상태 출력
        if (room.roomPlayerInfo.size() == m)
            cout << "Started!\n";
        else
            cout << "Waiting!\n";

        // 닉네임 기준 정렬
        sort(room.roomPlayerInfo.begin(), room.roomPlayerInfo.end(),
            [](const Player& a, const Player& b) {
                return a.name < b.name;
            });

        // 플레이어 출력
        for (auto& player : room.roomPlayerInfo)
        {
            cout << player.level << " " << player.name << "\n";
        }
    }
}