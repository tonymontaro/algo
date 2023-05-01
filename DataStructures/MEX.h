#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/sequences/mex.html#mex-with-array-updates

#define ll long long


class Mex {
private:
    map<ll, ll> frequency;
    set<ll> missing_numbers;
    vector<ll> A;

public:
    Mex(vector<ll> const& A) : A(A) {
        for (ll i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (ll x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    ll mex() {
        return *missing_numbers.begin();
    }

    void update(ll idx, ll new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};