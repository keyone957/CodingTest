#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> people(n);
    vector<int> result(n, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
    }
    
    for (int i = 0; i < n; ++i) {
        int position = people[i];
        
        // 현재 키가 i+1인 사람을 적절한 위치에 배치
        int j = 0, count = 0;
        while (count < position || result[j] != 0) {
            if (result[j] == 0) count++;
            j++;
        }
        result[j] = i + 1;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}
