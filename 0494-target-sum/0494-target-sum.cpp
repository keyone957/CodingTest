class Solution {
int answer;
int rich;
int numsCnt;
bool visited[1000];
vector<int> arr;
public :
void dfs(int cnt,int curSum)
{
    if(cnt==numsCnt)
    {
        if(curSum==rich)
        {
            answer++;
        }
        return;
    }
    dfs(cnt+1,curSum+arr[cnt]);
    dfs(cnt+1,curSum-arr[cnt]);
    

}
int findTargetSumWays(vector<int>& nums, int target) {
        
        rich=target;
        arr=nums;
        numsCnt=nums.size();
        dfs(0,0);
        return answer;
}

};