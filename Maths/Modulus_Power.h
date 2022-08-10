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
ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1;
    x = x % p; // Update x if it is more than or equal to p
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// helpful vid: https://www.youtube.com/watch?v=jkZ6c-uAl7Y&ab_channel=ARSLONGAVITABREVIS
int main() {
    // ifstream cin("../test_input.txt");
    fastInputOutput();

/*
 find: a^b^c % P
 Fermat's little theorem: a^(P-1) = 1 under mod P
 We know that a^b can be expressed as quotient * divisor + reminder : q * d + r
 Let's choose the divisor to be (P-1) for the b^c part of a^b^c.
 => b^c = q*(P-1) + r
 a^b^c = a^(q*(P-1) + r) = a^(q*(P-1)) * a^r = (a^(P-1))^q * a^r : all under mod P
 from Fermat's theorem: a^(P-1)=1 under mod P, therefore  (a^(P-1))^q = 1^q = 1
 hence a^b^c = a^r % P, where r = b^c % (P-1).
 */
    ll MOD = 1e9 + 7;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        ll r = mpow(b, c, MOD - 1);
        print(mpow(a, r, MOD));
    }

    return 0;
}