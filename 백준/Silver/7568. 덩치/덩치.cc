#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int,int>> people(N);

    for(int i=0; i<N; i++){
        cin >> people[i].first >> people[i].second; // weight, height
    }

    for(int i=0; i<N; i++){
        int rank = 1;
        for(int j=0; j<N; j++){
            if(people[j].first > people[i].first && people[j].second > people[i].second){
                rank++;
            }
        }
        cout << rank << " ";
    }
    return 0;
}
