#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while (cin >> s && s != "0") {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        if (s == rev_s) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
