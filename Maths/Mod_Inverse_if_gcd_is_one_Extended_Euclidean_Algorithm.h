#include <bits/stdc++.h>
using namespace std;
#define ll long long

class ModInverse {
public:
    // Function to find modulo inverse of A provided gcd(A, M) == 1
    /*
     * Explanation: let 1 = xA + yM
     *  1 % M = (xA) % M + (yM) % M
     *  since M % M = 0, this simplifies to 1 % M = (xA) % M
     *  therefore x is the multiplicative inverse on A under mod M
     *  Now, we can find x using Extended Euclidean Algorithm as explained
     *  in this video: https://www.youtube.com/watch?v=hB34-GSDT3k
     */
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