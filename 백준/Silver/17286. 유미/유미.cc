#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double get_dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    Point yumi;
    vector<Point> targets(3);
    
    cin >> yumi.x >> yumi.y;
    for(int i = 0; i < 3; i++) {
        cin >> targets[i].x >> targets[i].y;
    }

    vector<int> p = {0, 1, 2};
    double min_total = 1e9;

    do {
        double current_dist = get_dist(yumi, targets[p[0]]);
        current_dist += get_dist(targets[p[0]], targets[p[1]]);
        current_dist += get_dist(targets[p[1]], targets[p[2]]);
        
        if (current_dist < min_total) {
            min_total = current_dist;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << (int)min_total << endl;

    return 0;
}