class Solution {
int arrSize;
vector<vector<int>> answer;
vector<int> arr;
vector<int> cur;
bool isUsed[11];
public:
void dfs(int start)
{
    
    answer.push_back(cur);
    if(start==arrSize+1)
    {
        return;
    }
    for(int i =start;i<arrSize;i++)
    {
        if(!isUsed[i])
        {
            isUsed[i]=true;
            cur.push_back(arr[i]);
            dfs(i+1);
            isUsed[i]=false;
            cur.pop_back();
        }
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
    arrSize=nums.size();
    arr=nums;
    dfs(0);
    return answer;   
    }
};