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
vector<string> answer;
vector<vector<string>> inputArr;
vector<string> cur;
bool isVisit[300]={false};
int arrSize;
bool isAnswer=false;
void dfs(string start, int cnt)
{
    if(cnt==arrSize)
    {
        answer=cur;
        isAnswer=true;
        return;
    }
    if(isAnswer) return;
    for(int i=0;i<arrSize;i++)
    {
        if(isAnswer) return;
        string next=inputArr[i][1];
        if(!isVisit[i]&&inputArr[i][0]==start)
        {
            isVisit[i]=true;
            cur.push_back(next);
            dfs(next,cnt+1);
            cur.pop_back();
            isVisit[i]=false;
        }
    }
   
}
vector<string> solution(vector<vector<string>> tickets) {
   arrSize=tickets.size();
    sort(tickets.begin(),tickets.end());
    inputArr=tickets;
    cur.push_back("ICN");
    dfs("ICN",0);
    return answer;
}