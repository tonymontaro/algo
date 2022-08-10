#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define useFile() ifstream cin("../test_input.txt"); ofstream cout("../out.txt")
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl

#define ll long long
#define lb long double
// Question: https://atcoder.jp/contests/abc259/tasks/abc259_b
// Helpful vid: https://www.youtube.com/watch?v=OYuoPTRVzxY&ab_channel=patrickJMT
// wiki: https://en.wikipedia.org/wiki/Rotation_matrix

class Solution {
public:
    lb degreesToRad(lb deg) {
        return (deg * M_PI) / 180;
    }
    void run() {
        lb x, y, d; cin >> x >> y >> d;
        d = degreesToRad(d);
        lb x1 = x * cos(d) - y * sin(d);
        lb y1 = x * sin(d) + y * cos(d);
        cout << setprecision(6) << fixed;
        print2(x1, y1);
    }
};

int main() {
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}
