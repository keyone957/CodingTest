#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    int playerCnt=players.size();
    int callCnt=callings.size();
    map<string,int> name;
    map<int,string> rank;
    for(int i=0;i<playerCnt;i++)
    {
        rank.insert({i,players[i]});
        name.insert({players[i],i});
    }
   
    
    for(int i=0;i<callCnt;i++)
    {
        string caller = callings[i];       // 추월한 선수
        int callerRank = name[caller];     // 추월한 선수 현재 순위
        string loser = rank[callerRank-1]; // 추월당한 선수 이름

        // 1. 추월당한 선수 rank +1
        name[loser] = callerRank;
        // 2. 추월한 선수 rank -1
        name[caller] = callerRank - 1;
        // 3,4. rank맵도 동기화
        rank[callerRank] = loser;
        rank[callerRank - 1] = caller;
       
    }
    for(int i=0;i<playerCnt;i++)
    {
        answer.push_back(rank[i]);
    }
    
    return answer;
}