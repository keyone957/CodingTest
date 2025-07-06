#include <iostream>
#include <string>
using namespace std;

int main() {
    string remove = "CAMBRIDGE";
    string s;
    cin >> s;
    for (char c : s) {
        if (remove.find(c) == string::npos) cout << c;
    }
}
