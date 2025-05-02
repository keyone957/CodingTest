#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    set<char> lower = {'r', 'o', 'y', 'g', 'b', 'i', 'v'};
    set<char> upper = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    set<char> foundLower, foundUpper;

    for (char c : S) {
        if (lower.count(tolower(c))) {
            if (islower(c)) foundLower.insert(c);
            if (isupper(c)) foundUpper.insert(c);
        }
    }

    bool canLower = foundLower.size() == 7;
    bool canUpper = foundUpper.size() == 7;

    if (canLower && canUpper) cout << "YeS\n";
    else if (canLower) cout << "yes\n";
    else if (canUpper) cout << "YES\n";
    else cout << "NO!\n";

    return 0;
}
