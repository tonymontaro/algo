#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Used to create a unique tuple representing the equation of a line given two points.
// (credit: https://atcoder.jp/contests/abc248/editorial/3809)
// eq: Ax + By = C
// Example problem: https://atcoder.jp/contests/abc248/editorial/3809 (my solution: https://atcoder.jp/contests/abc248/submissions/31392081)
tuple<ll, ll, ll> normalizeLineEquation(ll x1, ll y1, ll x2, ll y2) {
    ll A = y2 - y1;
    ll B = x1 - x2;
    ll C = A*x1 + B*y1;
    if (A < 0 || (A == 0 && B < 0)) {
        A *= -1; B *= -1; C *= -1;
    }
    ll g = gcd(abs(A), abs(B));
    g = gcd(g, abs(C));
    A /= g; B /= g; C /= g;
    return {A, B, C};
}

#define pi pair<ll, ll>
// cross product given three points.
ll crossProduct(pi &a, pi &b, pi &c) {
    return ((a.first - b.first) * (c.second - b.second)) - ((a.second - b.second) * (c.first - b.first));
}