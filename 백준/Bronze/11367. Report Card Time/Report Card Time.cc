#include <iostream>
#include <string>

using namespace std;

string getGrade(int score) {
    if (score >= 97) return "A+";
    if (score >= 90) return "A";
    if (score >= 87) return "B+";
    if (score >= 80) return "B";
    if (score >= 77) return "C+";
    if (score >= 70) return "C";
    if (score >= 67) return "D+";
    if (score >= 60) return "D";
    return "F";
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        
        cout << name << " " << getGrade(score) << endl;
    }
    
    return 0;
}