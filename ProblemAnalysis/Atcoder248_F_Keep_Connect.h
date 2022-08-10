#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl


template <typename T>
void printArr(T &arr) {
    for (auto x: arr) cout << x << " ";
    cout << endl;
}

#define ll long long
#define lb long double
const int INF = (int)2e9;
const ll LINF = (ll)4e18;
ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1; x = x % p;  if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
// same as count = __builtin_popcount((unsigned int) num);
ll popcount(ll num) {
    ll res = 0;
    while (num > 0) { res += (1 & num); num >>= 1; }
    return res;
}
ll MOD = 1e9 + 7;

ll hashNum(ll a) {
    return a * (a + 1346) * (a + 9185);
}
#define tp tuple<ll, ll, ll, ll>
class Solution {
public:
    void run() {
        ll n, mod;
        cin >> n >> mod;

        // problem: https://atcoder.jp/contests/abc248/tasks/abc248_f
        // solution from: https://atcoder.jp/contests/abc248/submissions/31250707
        vector<ll> dp(n);
        vector<ll> cum1(n);
        vector<ll> cum2(n);

        for (ll i = 0; i < n; i++) {
            for (int j = 1; j < i; ++j) {
                dp[j] = (cum1[i - j - 1] + cum2[i - j]) % mod;
            }
            dp[i] = (cum2[0] + 1) % mod;
            for (ll j = 0; j < i + 1; j++)
                cum1[j] = (cum1[j] + dp[i-j]) % mod;
            for (ll j = 0; j < i + 1; j++)
                cum2[j] = (cum2[j] + cum1[j] * 2) % mod;
        }
        for (ll i = n - 2; i >= 0; i--)
            cout << cum1[i] << " ";
    }
};



int main() {
    fastInputOutput();

    Solution solver;
    solver.run();

    return 0;
}
