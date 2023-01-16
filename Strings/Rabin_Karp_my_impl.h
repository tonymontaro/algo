#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>

//using lm = ::atcoder::modint998244353;
using lm = ::atcoder::modint1000000007;
#define ll long long

ll rabinkarp(string &t, string &s) {
        if (s.size() > t.size()) return -1;
        ll n = t.size();
        vector<lm> power(n);
        power[0] = 1;
        ll mult = 27;
        for (ll i = 1; i < n; i++) {
            power[i] = power[i-1] * mult;
        }
        lm sHash = 0;
        for (ll i = 0; i < s.size(); i++) {
            sHash += power[i] * (s[i] - 'a' + 1);
        }

        vector<lm> tHash(n + 1);
        for (ll i = 0; i < n; i++) {
            tHash[i + 1] = tHash[i] + power[i] * (t[i] - 'a' + 1);
            if (i >= s.size()-1) {
                lm subHash = tHash[i + 1] - tHash[i + 1 - s.size()];
                ll powerToRemove = i + 1 - s.size();
                subHash = subHash / (lm(mult).pow(powerToRemove));

                if (subHash == sHash) return i - s.size() + 1;
            }
        }
        return -1;
    }