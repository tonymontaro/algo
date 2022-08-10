#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

int main(){
    /* (a / x) % mod = ?
     *  1/x === mpow(x, mod - 2, mod)
     * example
     * (9 * 10) * 1/2  MOD 998244353
     *  == 9 * 10 * mpow(2, mod-2, mod)
     */
    ll mod = 998244353;
    ll first = (9 * 10) / 2;
    cout << first << endl;
    ll invTwo = mpow(2, mod - 2, mod);
    ll ans = (9 * 10 * invTwo) % mod;
    cout << ans << endl;
}