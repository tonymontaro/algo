#include <bits/stdc++.h>
using namespace std;
#define ll long long

// video: https://www.youtube.com/watch?v=hB34-GSDT3k
ll gcdExtended(ll a, ll b, ll* x, ll* y) {
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// Example problem: https://atcoder.jp/contests/abc340/tasks/abc340_f
// Solution with explanation: https://atcoder.jp/contests/abc340/submissions/50215048