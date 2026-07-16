// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int arrSize=nums.size();
//         vector<int> answer;
//         priority_queue<pair<int,int>> window;
//         int left=0;
//         for(int i=0;i<k;i++)
//         {
//             window.push({nums[i],i});
//         }

//         answer.push_back(window.top().first);
//         left++;   

        
//         for(int i=1;i<arrSize-k+1;i++)
//         {
//             window.push({nums[i+k-1],i+k-1});
//             // 다음 인덱스의 값을 먼저 push
//             while(!window.empty()&&window.top().second<left)
//             {
//                 window.pop();
//                 //윈도우 크기의 범위를 벗어난 값을 pop시킴
//             }
//             answer.push_back(window.top().first);

//             left++;
//         }
//         return answer;
//     }
// };
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;

        // {값, 인덱스}
        deque<pair<int, int>> dq;

        for (int i = 0; i < nums.size(); i++) {
            int left = i - k + 1;

            // 1. 현재 윈도우의 범위를 벗어난 원소 제거
            while (!dq.empty() && dq.front().second < left) {
                dq.pop_front();
            }

            // 2. 현재 값보다 작거나 같은 값 제거
            while (!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }

            // 3. 현재 값과 인덱스를 덱에 추가
            dq.push_back({nums[i], i});

            // 4. 크기가 k인 윈도우가 완성되면 최댓값 저장
            if (i >= k - 1) {
                answer.push_back(dq.front().first);
            }
        }

        return answer;
    }
};