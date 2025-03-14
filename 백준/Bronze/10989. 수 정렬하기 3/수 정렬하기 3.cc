#include <iostream>
using namespace std;

int cnt[10001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, tmp;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        cnt[tmp]++;
    }
    
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << "\n";
        }
    }
}