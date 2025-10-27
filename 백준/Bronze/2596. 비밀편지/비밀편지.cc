#include <iostream>
#include <string>
using namespace std;

string decode(string s) {
    string result = "";
    for (int i = 0; i < s.size(); i += 6) {
        string code = s.substr(i, 6);
        string table[8] = {
            "000000", "001111", "010011", "011100",
            "100110", "101001", "110101", "111010"
        };
        char letter = 'A';
        int minDiff = 6, idx = -1;
        for (int j = 0; j < 8; j++) {
            int diff = 0;
            for (int k = 0; k < 6; k++)
                if (code[k] != table[j][k]) diff++;
            if (diff < minDiff) {
                minDiff = diff;
                idx = j;
            }
        }
        if (minDiff > 1) return to_string(i / 6 + 1);
        result += (letter + idx);
    }
    return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << decode(s);
}
