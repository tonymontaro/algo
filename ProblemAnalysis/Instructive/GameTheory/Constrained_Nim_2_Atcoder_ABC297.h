#include <bits/stdc++.h>
using namespace std;

string delim = " ";
#define print(x) cout << setprecision(16) << fixed << x << endl
#define ll long long

/*
 First understand Sprague-Grundy-Theorem: https://www.youtube.com/watch?v=GRlGknQEOW8
 The NIM for multiple games, a, b, c ... = nim(a) ^ nim(b) ^ nim(c) ... (where ^ = XOR)
 The game is lost if overall nim is 0, and won otherwise.
 Hence, the main problem is computing the nim for each pile.

 This problem involves observing the pattern for the NIM and translating that into a formula.
 Take an example: L=2, R=6, the first few nim values are as follows
 Nums: 0 1 2 3 5 6 7 8 9 10 11 12 13 ...
 Nims: 0 0 1 1 2 2 3 3 0 0  1  1  2  ...

 Another example: L=3, R=5
 Nums: 0 1 2 3 4 5 6 7 8 9 10 11 12 ...
 Nims: 0 0 0 1 1 1 2 2 0 0 0  1  1  ...

 Observations:
 - The pattern repeats every L+R
 - Each pattern starts from 0 and increases by 1 every L
 Hence the formula is: (x % (L+R)) / L
 */
class Solution {
public:
    ll n, m, q, k;
    void run() {
        ll l, r;
        cin >> n >> l >> r;
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            ll grundyNum = (a % (l + r)) / l;
            res = (res ^ grundyNum);
        }
        print((res == 0 ? "Second" : "First"));
    }
};

int main() {
//    fastInputOutput();
//    usefile();

    Solution sol;
    sol.run();

    return 0;
}
