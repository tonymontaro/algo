#include <bits/stdc++.h>
using namespace std;
#define ll long long

class ModInverse {
public:
    // Function to find modulo inverse of a NOTE: provided gcd(a, M) == 1
    ll modInverse(ll A, ll M) {
        ll x, y;
        ll g = gcdExtended(A, M, &x, &y);
        if (g != 1) {
            throw invalid_argument("Inverse doesn't exist");
        }
        else {
            // m is added to handle negative x
            ll res = (x % M + M) % M;
            return res;
        }
    }

private:
// Function for extended Euclidean Algorithm
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
};