#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s;
    cin >> s;

    istringstream ss(s);
    string num;
    int result = 0, sum = 0;
    bool minus = false;

    while (getline(ss, num, '+')) {
        size_t pos = num.find('-');
        if (pos != string::npos) {
            istringstream sub_ss(num);
            string sub_num;
            while (getline(sub_ss, sub_num, '-')) {
                int n = stoi(sub_num);
                if (minus) result -= n;
                else {
                    result += sum;
                    sum = n;
                    minus = true;
                }
            }
        } else {
            int n = stoi(num);
            if (minus) result -= n;
            else sum += n;
        }
    }
    result += sum;
    cout << result;
    return 0;
}
