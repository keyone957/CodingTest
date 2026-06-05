class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIdx=0;
        int rightIdx=numbers.size()-1;
        vector<int> answer;
        while(leftIdx<rightIdx)
        {
            int sum=numbers[leftIdx]+numbers[rightIdx];
            if(sum<target)
            {
                leftIdx++;
            }
            else if(sum>target)
            {
                rightIdx--;
            }
            else if(sum==target)
            {
                break;
            }
        }
        leftIdx++;
        rightIdx++;
        answer.push_back(leftIdx);
        answer.push_back(rightIdx);


        return answer;
    }
};