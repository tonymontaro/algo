#include <bits/stdc++.h>
using namespace std;
// article: https://cp-algorithms.com/combinatorics/binomial-coefficients.html#properties


#define ll long long

ll C(ll n, ll k) {
    long double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}