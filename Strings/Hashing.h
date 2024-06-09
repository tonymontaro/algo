#include <bits/stdc++.h>
using namespace std;

// Good Example: https://atcoder.jp/contests/abc284/tasks/abc284_f
// My submission: https://atcoder.jp/contests/abc284/submissions/49896944
/*
Using AtCoder ModInt Lib makes it very easy to compute string hashes. Idea:
lm pw = 1;
lm mult = 130;
string s = "tobehashed";
vector<lm> hashes(n);
for (ll i = 0; i <= n; i++) {
   hashes[i] = s[i] * pw;
   if (i > 0) hashes[i] += hashes[i-1];
}

 */


// https://cp-algorithms.com/string/string-hashing.html -> Fast hash calculation of substrings of given string
namespace Hashing {
    #define ll long long
    const ll MX = 1e5 + 2;
    ll powers[MX];
    ll table[MX];
    const ll mult = 131;
    const ll MOD = 1e9 + 7;
    int N;
    void computeTables(const string &s) {
        N = s.size();
        powers[0] = 1;
        table[0] = s[0];
        for (int i = 1; i < N; i++) {
            powers[i] = (powers[i - 1] * mult) % MOD;
            table[i] = (table[i - 1] + (powers[i] * s[i])) % MOD;
        }
    }
    ll getSubstringHash(int left, int right) {
        ll h = table[right];
        if (left > 0) h -= table[left - 1];
        h = (h * powers[N - right - 1]) % MOD;
        return h;
    }
}