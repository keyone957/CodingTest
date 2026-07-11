class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         deque<int> dq;
//         dq.assign(nums.begin(),nums.end());
        
//         for(int i=0;i<k;i++)
//         {
//             int back=dq.back();
//             dq.pop_back();
//             dq.push_front(back);
//         }

//         nums.assign(dq.begin(),dq.end());
//     }
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int left =0;
        int right=nums.size()-1;
        while(left<right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        int left2=0;
        int right2=k-1;
        while(left2<right2)
        {
           swap(nums[left2], nums[right2]);
            left2++;
            right2--;
        }
        int left3=k;
        int right3=nums.size()-1;
        while(left3<right3)
        {
           swap(nums[left3], nums[right3]);
            left3++;
            right3--;
        }
    }
};