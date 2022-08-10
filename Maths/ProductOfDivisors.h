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
ll MOD = 1e9 + 7;
ll modMultiply(ll a, ll b) {
    a %= MOD;
    b %= MOD;
    return (a * b) % MOD;
}

ll getGeometricProgressionSum(ll a, ll k) {
    ll dividend = (mpow(a, k + 1, MOD) - 1 + MOD) % MOD;
    ll divisor = a - 1;
    ll divisorInverse = mpow(divisor, MOD - 2, MOD);
    ll res = (dividend * divisorInverse) % MOD;
    return res;
}

// Solve for the productOfDivisors using the trick below
// let's take an example, divisors of n = 1, 2, 3, 6 where n=6 (the actual number being factorized)
// product = (1 * 2 * 3 * 6)
// product * product =  (1 * 2 * 3 * 6) *  (1 * 2 * 3 * 6)
// now pair the values so that a * b = n
// product * product = (1 * 6) * (2 * 3) * (3 * 2) * (6 * 1)
// product^2 = n * n * n * n = n^(numberOfDivisors)
// now take the square root of both sides (or a^(1/2))
// product = n^(numberOfDivisors / 2)
// numberOfDivisors can only be odd when all (pw + 1) are odd i.e. all pw are even.
ll getProductOfDivisors(vector<pair<ll, ll>> &primeFactors, bool allEvenPowers) {
    // computing n^(sumDivisors/2) => a^(k*sumDivisors/2).....z^(k*sumDivisors/2)
    // if allEven, k/2 for factors. Compute sumDivisors % MOD-1 (fermat little theorem)
    // if !allEven, choose one (pw + 1), divide by two and continue computing sumDivisors
    bool used = false;
    ll sumDivisors = 1;
    for (int i = 0; i < primeFactors.size(); i++) {
        ll pw = primeFactors[i].second + 1;
        if (!allEvenPowers && !used && pw % 2 == 0) {
            used = true;
            pw /= 2;
        }
        sumDivisors = (sumDivisors * pw) % (MOD - 1);
    }
    ll productOfDivisors = 1;
    for (int i = 0; i < primeFactors.size(); i++) {
        ll prime = primeFactors[i].first, pw = primeFactors[i].second;
        if (allEvenPowers) pw /= 2;
        ll rs = (pw * sumDivisors) % (MOD - 1);
        productOfDivisors = (productOfDivisors * mpow(prime, rs, MOD)) % MOD;
    }
    return productOfDivisors;
}


