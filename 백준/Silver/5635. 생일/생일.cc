#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string youngestName, oldestName;
    int yDay, yMonth, yYear;
    int oDay, oMonth, oYear;

    for (int i = 0; i < n; i++) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;

        if (i == 0) {
            youngestName = oldestName = name;
            yDay = oDay = d;
            yMonth = oMonth = m;
            yYear = oYear = y;
            continue;
        }

        // youngest (latest date)
        if (y > yYear || 
           (y == yYear && (m > yMonth || (m == yMonth && d > yDay)))) {
            youngestName = name;
            yDay = d; yMonth = m; yYear = y;
        }

        // oldest (earliest date)
        if (y < oYear || 
           (y == oYear && (m < oMonth || (m == oMonth && d < oDay)))) {
            oldestName = name;
            oDay = d; oMonth = m; oYear = y;
        }
    }

    cout << youngestName << '\n' << oldestName << '\n';
    return 0;
}
