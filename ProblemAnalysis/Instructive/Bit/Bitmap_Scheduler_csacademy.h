#include <bits/stdc++.h>
using namespace std;

// Question: https://csacademy.com/ieeextreme-practice/task/scheduler/

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }


#define ll long long
ll MOD = 1e9 + 7;
const ll MX_BIT = 100021;

ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1;
    x = x % p;
    if (x == 0) return 0;  // In case x is divisible by p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}
class Compare {
public:
    bool operator() (bitset<MX_BIT> & a, bitset<MX_BIT> & b) {
        return compare(a, b);
    }
    static bool compare (bitset<MX_BIT> & a, bitset<MX_BIT> & b) {

        const uint64_t * p = (const uint64_t *)(&a);
        const uint64_t * q = (const uint64_t *)(&b);

        const uint64_t * r = p;

        int i= (sizeof(bitset<MX_BIT>)-1)/sizeof(uint64_t);

        for (p+=i, q+=i; (p>=r) && (*p==*q); --p, --q) {}

        return *p<*q;
    }
};

class Solution {
public:
    ll n, m;
    void run() {
        cin >> n >> m;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<>());
        vector<bitset<MX_BIT>> bits(m);
        for (ll i = 0; i < min(m, n); i++) {
            bitset<MX_BIT> a;
            a.set(arr[i]);
            bits[i] = a;
        }

        for (ll i = m; i < n; i++) {
            ll idx = 0;
            for (ll j = 0; j < m; j++) {
                if (Compare::compare(bits[j], bits[idx])) idx = j;
            }
            for (ll j = arr[i]; j < MX_BIT; j++) {
                if (bits[idx][j]) {
                    bits[idx][j] = false;
                } else {
                    bits[idx].set(j);
                    break;
                }
            }
        }
        ll idx = 0;
        for (ll j = 0; j < m; j++) {
            if (Compare::compare(bits[idx], bits[j])) idx = j;
        }
        auto &last = bits[idx];
        ll res = 0;
        for (ll i = 0; i < MX_BIT; i++) {
            if (last[i]) {
                ll rs = mpow(2, i, MOD);
                res = (res + rs) % MOD;
            }
        }
        cout << res << endl;
    }
};

int main(){
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}
