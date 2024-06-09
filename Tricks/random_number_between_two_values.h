#include <bits/stdc++.h>

using namespace std;

#define ll long long

// e.g.   ll a = (1ll << 62) / 100;
//    ll b = (1ll << 61) / 100;
ll random_number_between(ll a, ll b) {
    if (a > b) swap(a, b);
    mt19937 rng(3245);
    uniform_int_distribution<ll> gen(a, b);
    return gen(rng);
}