class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int arrSize=people.size();
        int answer=0;
        int leftIdx=0;
        int rightIdx=arrSize-1;

        while(leftIdx<=rightIdx)
        {
            int left=people[leftIdx];
            int right=people[rightIdx];
            int sum =left+right;
            if(sum<=limit)
            {
                leftIdx++;
                rightIdx--;
                answer++;
            }
            else
            {
                rightIdx--;
                answer++;
            }

        }
        return answer;
    }
};