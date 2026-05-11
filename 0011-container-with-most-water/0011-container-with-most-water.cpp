class Solution {
public:
    int maxArea(vector<int>& height) {
        int arrSize=height.size();
        int answer=-1;
        int left=0;
        int right=arrSize-1;
        while(left<right)
        {
            int leftV=height[left];
            int rightV=height[right];
            int rSize=abs(left-right)*min(leftV,rightV);
            if(leftV<rightV)
            {
                left++;
            }
            else
            {
                right--;
            }
            answer=max(answer,rSize);
        }
        return answer;
    }
};