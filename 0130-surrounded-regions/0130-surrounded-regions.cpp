class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4] = { 0,0,-1,1 };
        int dy[4] = { -1,1,0,0 };
        int y = board.size();
        int x = board[0].size();

        int check[201][201] = { 0 };
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if(i==0||j==0||i==y-1||j==x-1) continue;
                if (!check[i][j] && board[i][j] == 'O')
                {
                    queue<pair<int, int>> q;
                    vector<pair<int,int>> setArea;
                    q.push({ i,j });
                    setArea.push_back({i,j});
                    check[i][j] = 1;
                    bool isAround = false;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front(); q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            int nextY = cur.first + dy[i];
                            int nextX = cur.second + dx[i];
                            
                            if (nextY < 0 || nextX < 0 || nextY >= y || nextX >= x) continue;
                            if (check[nextY][nextX]!=0) continue;
                            if (board[nextY][nextX] == 'X') continue;
                            if (nextX == 0 || nextY == 0 || nextY == y - 1 || nextX == x - 1)
                            {
                                isAround = true;
                            }
                            check[nextY][nextX] = 1;
                            q.push({ nextY,nextX });
                            setArea.push_back({nextY,nextX});
                           
                        }
                    }
                    if(!isAround)
                    {
                        for(int i=0;i<setArea.size();i++)
                        {
                            check[setArea[i].first][setArea[i].second]=2;
                        }
                       
                    }

                }
            }
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(check[i][j]==2)
                {
                    board[i][j]='X';
                }
            }
        }
    }

};