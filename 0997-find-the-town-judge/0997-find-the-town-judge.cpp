class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        int answer=-1;
         int in[1001]={0};
        int out[1001]={0};
        for(int i=0;i<trust.size();i++)
        {
            int start=trust[i][0];
            int end=trust[i][1];
            in[end]++;
            out[start]++;
        }
       for(int i=1;i<=n;i++)
       {
        if(out[i]==0&&in[i]==n-1)
        {
            answer=i;
        }
       }
        return answer;
    }
};