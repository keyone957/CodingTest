class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int arrSize=nums.size();
        vector<int> answer;
        priority_queue<pair<int,int>> window;
        int left=0;
        int right=k;
        for(int i=0;i<k;i++)
        {
            window.push({nums[i],i});
            //
        }

        answer.push_back(window.top().first);
        // cout<<answer[0];       
        left++;   
        for(int i=1;i<arrSize-k+1;i++)
        {
            window.push({nums[i+k-1],i+k-1});
            while(!window.empty()&&window.top().second<left)
            {
                window.pop();
            }
            answer.push_back(window.top().first);

            left++;
        }
        return answer;
    }
};