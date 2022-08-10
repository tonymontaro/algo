#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define useFile() ifstream cin("../test_input.txt"); ofstream cout("../out.txt")
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl


template <typename T>
void printArr(T &arr) {
    for (auto x: arr) cout << x << " ";
    cout << endl;
}
string bin_string(long long num) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res += (num & 1) + '0';
        num >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
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

#define ll long long
#define pi pair<long, long>
// get the bit set value at index idx
#define bit(num, idx) ((num >> idx) & 1)

// problem: https://atcoder.jp/contests/abc261/tasks/abc261_e
class Solution {
public:
    void run() {
        ll n, c; cin >> n >> c;
        vector<ll> ans(n);
        vector<pi > ops(n);
        for (ll i = 0; i < n; i++) cin >> ops[i].first >> ops[i].second;

        for (ll i = 0; i < 31; i++) {
            ll prevBit = bit(c, i);
            vector<ll> transform = {0, 1};
            for (ll j = 0; j < n; j++) {
                ll opBit = bit(ops[j].second, i);
                vector<ll> t;
                if (ops[j].first == 1) t = {0 & opBit, 1 & opBit};
                if (ops[j].first == 2) t = {0 | opBit, 1 | opBit};
                if (ops[j].first == 3) t = {0 ^ opBit, 1 ^ opBit};
                transform = {t[transform[0]], t[transform[1]]};

                prevBit = transform[prevBit];
                ans[j] |= (prevBit << i);
            }
        }
        for (ll i = 0; i < n; i++) print(ans[i]);
    }
};

#define bit(x,i)(((x)>>(i))&1)
int main(){
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}