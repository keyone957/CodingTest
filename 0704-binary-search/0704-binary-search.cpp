class Solution {
public:
    int search(vector<int>& nums, int target) {
        int answer;
        int arrSize=nums.size();
        bool isFound=false;
        int left=0;
        int right=arrSize-1;

        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                answer=mid;
                isFound=true;
                break;
            }
        }
        if(!isFound)
        {
            answer=-1;
        }
        return answer;
    }
};