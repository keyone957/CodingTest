#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minElement(std::vector<int>& nums) {
        int min_val = INT_MAX;

        for (int num : nums) {
            int digit_sum = 0;
            int temp = num;
            
            // 각 자릿수의 합 계산
            while (temp > 0) {
                digit_sum += temp % 10;
                temp /= 10;
            }

            // 최솟값 갱신
            min_val = std::min(min_val, digit_sum);
        }

        return min_val;
    }
};