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

ll Combination(ll n, ll k) {
    long double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}

// Modular Combinatorics
class ModCombination{
public:
    vector<ll> fact;
    ll p;
    ModCombination(ll n, ll mod) {
        p = mod;
        fact.resize(n + 1);
        fact[0] = 1;
        for (ll i = 1; i < n + 1; i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
    }
    ll powmod(ll a, ll b){
        a %= p;
        if (a == 0) return 0;
        ll product = 1;
        while(b > 0){
            if (b&1){    // you can also use b % 2 == 1
                product *= a;
                product %= p;
                --b;
            }
            a *= a;
            a %= p;
            b /= 2;    // you can also use b >> 1
        }
        return product;
    }
    ll inv(ll a){
        return powmod(a, p-2);
    }
    ll nCk(ll n, ll k){
        return ((fact[n] * inv(fact[k]) % p) * inv(fact[n-k])) % p;
    }
};