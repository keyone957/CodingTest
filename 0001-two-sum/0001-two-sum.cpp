class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        map<int, int> indices;
        indices[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++) {
            auto it = indices.find(target - nums[i]);
            if(it != indices.end()) {
                ret[0] = it->second;
                ret[1] = i;
                break;
            }            
            indices[nums[i]] = i;
        }

        return ret;
    }
};