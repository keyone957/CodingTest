/*
deadends를 만나면 그 길은 유효하지 않는 길임.
만약에 deadends에 있는 값을 만나면 큐에 넣지 않고 걍 패스
*/

vector<string>checkArr;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool visited[10000]={};
        bool dead[10000]={};
        // => deadends에 있는 문자열들을 구분하기 위한 bool배열
        //원래 while문 안에서 계속 for문을 돌면서 확인했지만 => 시간초과로 오답
        // 따라서 단순 bool배열을 갱신을 해 놓고 이 배열에서 확인하자. 
        int answer=0;
        bool isEnd=false;
        checkArr=deadends;
        for(int i=0;i<deadends.size();i++)
        {
            if(deadends[i]=="0000") { isEnd=true; return -1; }
            //0000이 있으면 처음부터 모든 타겟에 도달 못함
            dead[stoi(deadends[i])]=true;
        }
        // if(isEnd) 
        // {
        //  return -1;
        // }
        queue<pair<string,int>> q;
        //현재 자물쇠의 상태와 이동 횟수를 q에 저장
        q.push({"0000",0});
        visited[0]=true;
        while(!q.empty())
        {
            pair<string,int> cur=q.front();
            q.pop();
            if(cur.first==target)
            {
                answer=cur.second;
                break;
            }
            for(int i=0;i<4;i++)
            //=> 각 자리 마다 증가 하거나 감소 하는 방향이 있으므로
            //
            {
                string upNext=cur.first;
                string downNext=cur.first;
                
                int digit=cur.first[i]-'0';
                int upDigit=(digit+1)%10;
                int downDigit=(digit+9)%10;

                upNext[i]=upDigit+'0';
                downNext[i]=downDigit+'0';

                if(!dead[stoi(upNext)]&&!visited[stoi(upNext)])
                {
                    visited[stoi(upNext)]=true;
                    q.push({upNext,cur.second+1});
                    
                }
                if(!dead[stoi(downNext)]&&!visited[stoi(downNext)])
                {
                    visited[stoi(downNext)]=true;
                    q.push({downNext,cur.second+1});
                   
                }

            }
        }
        if(!visited[stoi(target)])
        {
            answer=-1;
        }
        return answer;
    }
};