class Solution {
public:
    bool canFinish(int numCnt, vector<vector<int>>& inputArr) {
        bool answer=false;
        int indegree[2001]={0,};
        vector<int> linkedArr[5001];
        vector<int> result;
        queue<int> q;
        for(int i =0;i<inputArr.size();i++)
        {
            int end=inputArr[i][1];
            int start=inputArr[i][0];
            indegree[end]++;
            linkedArr[start].push_back(end);
        }
        for(int i=0;i<numCnt;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            result.push_back(cur);
            for(int i=0;i<linkedArr[cur].size();i++)
            {
                int next=linkedArr[cur][i];
                indegree[next]--;
                if(indegree[next]==0)
                {
                
                    q.push(next);
                }
            }
        }
        if(result.size()==numCnt)
        {
            answer=true;
        }
        else
        {
            answer=false;
        }
        return answer;
    }
};