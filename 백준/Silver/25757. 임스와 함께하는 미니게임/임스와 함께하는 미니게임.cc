#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    char game;
    cin >> N >> game;

    set<string> players;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        players.insert(name);
    }

    int unique_count = players.size();

    if (game == 'Y') {
        cout << unique_count << "\n";
    } else if (game == 'F') {
        cout << unique_count / 2 << "\n";
    } else if (game == 'O') {
        cout << unique_count / 3 << "\n";
    }

    return 0;
}