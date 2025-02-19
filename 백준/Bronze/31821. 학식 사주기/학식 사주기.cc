#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, total = 0;
    cin >> N;
    
    vector<int> menu(N + 1); // 1-based index를 사용하기 위해 크기를 N+1로 설정
    
    for (int i = 1; i <= N; i++) {
        cin >> menu[i];
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int B;
        cin >> B;
        total += menu[B];
    }
    
    cout << total << endl;
    
    return 0;
}
