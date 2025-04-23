#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;

int main() {
    string line, word, result;
    getline(cin, line);
    istringstream iss(line);
    unordered_set<string> skip = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
    bool first = true;
    while (iss >> word) {
        if (first || skip.find(word) == skip.end()) {
            result += toupper(word[0]);
        }
        first = false;
    }
    cout << result;
    return 0;
}
