class Solution {
bool visited[16][16];
char inputArr[16][16];
int count=0;
bool answer=false;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int sizeX,sizeY;
vector<pair<int,int>> startPoints;
string target;
void dfs(int y,int x,int cnt)
{
    if(cnt==count)
    {
        answer=true;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextY<0||nextX<0||nextX>=sizeX||nextY>=sizeY)continue;
        if(visited[nextY][nextX]) continue;
        if(inputArr[nextY][nextX]!=target[cnt]) continue;
        visited[nextY][nextX]=true;
        dfs(nextY,nextX,cnt+1);
        visited[nextY][nextX]=false;
    }

}
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        count=word.length();
        int startY,startX;
        bool find=false;
        sizeY=board.size();
        sizeX=board[0].size();
        target=word;

        for(int i=0;i<sizeY;i++)
        {
            for(int j=0;j<sizeX;j++)
            {
                inputArr[i][j]=board[i][j];
                if(board[i][j]==word[0])
                {
                    startPoints.push_back({i,j});
                }
            }
        }
        if(sizeY*sizeX<target.size())
        {
           answer=false;
        }
        else
        {
            for(int i=0;i<startPoints.size();i++)
            {
                visited[startPoints[i].first][startPoints[i].second]=true;
                dfs(startPoints[i].first,startPoints[i].second,1);
                memset(visited, false, sizeof(visited));
            }
        }
        return answer;
    }
};