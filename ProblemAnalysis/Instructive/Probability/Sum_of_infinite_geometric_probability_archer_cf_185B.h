#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }
#define print(x) cout << setprecision(10) << fixed <<  x << endl

#define ll long long
#define lb long double

/*
Question: https://codeforces.com/contest/312/problem/B
p = a/b
q = c/d
r = (1 - p)*(1 - q) # both miss
t1 = p
t2 = p * r
t3 = p * r^2
 ...
tn = p * r^(n-1)

Sn = (p * (1 - r^n)) / (1 - r)
since r < 0, r^n -> 0 as n -> infinity
S_infinity = p / (1 - r)

 */
class Solution {
public:
    void run() {
        lb a, b, c, d; cin >> a >> b >> c >> d;
        lb p = a / b;
        lb q = c / d;
        lb r = ((lb)1 - p) * ((lb)1 - q);
        lb S_infinity = p / (1 - r);
        print(S_infinity);
    }
};

int main(){
    fastInputOutput();
//    usefile();

    Solution sol;
    sol.run();

    return 0;
}

