#include <string>
#include <vector>
#include<iostream>
long long fact[21];
// 1부터 n까지의 팩토리얼을 미리 계산해두는 함수
void initFactorial(int n) 
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        fact[i] = fact[i - 1] * i;
    }
}
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    for(int i=1;i<=20;i++)
    {
        num.push_back(i);
    }
    initFactorial(n);
 // 컴퓨터 인덱스(0부터 시작)와 맞추기 위해 k에서 1을 빼고 시작함
    // 이렇게 해야 몫과 나머지가 딱 들어맞음
    k--; 
    
    // 자릿수 n개를 하나씩 채워나가는 루프
    while (n > 0) {
        // 현재 자릿수를 제외한, 뒤에 남은 자릿수들로 만들 수 있는 묶음(블록)의 크기
        // 예: n=4일 때 첫 자리를 정하려면 뒤에 3자리가 남으므로 3! (fact[3])이 묶음 크기임
        long long blockSize = fact[n - 1];
        
        // k를 묶음 크기로 나눈 '몫'이 현재 자리에 들어올 숫자의 대기열 인덱스가 됨
        int index = k / blockSize;
        
        // 해당 인덱스의 숫자를 정답 배열에 추가
        answer.push_back(num[index]);
        
        // 이미 사용한 숫자는 대기열에서 삭제 (중복 사용 방지)
        num.erase(num.begin() + index);
        
        // 다음 자릿수를 구하기 위해, k를 방금 구한 '나머지' 값으로 갱신
        k %= blockSize;
        
        // 남은 자릿수를 하나 줄임
        n--;
    }
    return answer;
}