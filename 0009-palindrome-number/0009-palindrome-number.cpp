class Solution {
public:
    bool isPalindrome(int x) {
        // 음수는 회문이 될 수 없습니다 (예: -121 -> 121-).
        // 또한, 0으로 끝나면서 0이 아닌 숫지도 회문이 될 수 없습니다 (예: 10 -> 01).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        // 숫자의 절반만 뒤집을 때까지 반복합니다.
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 숫자의 길이가 홀수일 때는 revertedNumber / 10을 통해 가운데 숫자를 제거하고 비교합니다.
        // 예: 12321에서 x = 12, revertedNumber = 123일 때, 12 == 123/10
        return x == revertedNumber || x == revertedNumber / 10;
    }
};