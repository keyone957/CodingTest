class Solution {
public:
    int numSquares(int n) {
        int answer=0;
        queue<int> q;
        bool isVisited[10001]={false};
        q.push({n});
        isVisited[n]=true;
        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                int cur =q.front();
                q.pop();
                for(int i=1;i*i<=cur;i++)
                {
                    int num=cur-i*i;
                    if(!isVisited[num])
                    {
                        q.push(num);
                        isVisited[num]=true;
                    }
                    if(num==0)
                    {
                        return answer+1;
                    }
                }
            }
            
            answer++;
            
        }   
        return answer;
    }
};