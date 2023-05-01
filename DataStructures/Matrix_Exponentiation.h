#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>

class MatrixPower { // for n by n matrix
public:
    vector<vector<ll>> power(vector<vector<ll>> &A, ll p) {
        ll n = A.size();
        vector<vector<ll>> result(n, vector<ll>(n));
        for (ll i = 0; i < n; i++) result[i][i] = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                result = multiply(result, A);
            }
            p /= 2;
            A = multiply(A, A);
        }
        return result;
    }

private:
    vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B) {
        ll n = A.size();
        vector<vector<ll>> product(n, vector<ll>(n));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                for (ll k = 0; k < n; k++) {
                    product[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return product;
    }
};
