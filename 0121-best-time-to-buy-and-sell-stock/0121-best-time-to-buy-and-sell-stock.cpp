class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int right=1;
        int arrSize=prices.size();
        int answer=-1;
        while(left<arrSize&&right<arrSize)
        {
            int leftV=prices[left];
            int rightV=prices[right];
            if(rightV>=leftV)// 우측값이 왼쪽 값보다 크다면 갱신
            {
                answer=max(answer,rightV-leftV);
                right++;
            }
            else//더 싼가격이면
            {
                left=right;
                right++;
            }
        }
        if(answer<=-1)
        {
            answer=0;
        }
        return answer;
    }
};