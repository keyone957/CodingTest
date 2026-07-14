class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int arrCnt=stones.size();
        priority_queue<int> pq;
        int answer;
        for(int i=0;i<arrCnt;i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>=2)
        {
            int sum;
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            sum=first-second;
            if(sum>0)
            {
                pq.push(sum);
            }
        }
        if(pq.empty())
        {
           return 0;
        }
        
        return pq.top();
    }
};