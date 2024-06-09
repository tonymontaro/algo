#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>
ll MOD = 1e9 + 7;

// Question: https://leetcode.com/contest/weekly-contest-360/problems/maximize-value-of-function-in-a-ball-passing-game/
class Solution {
public:
    ll mx = 35;
    ll n;
    vector<vector<pi>> ansc;
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        n = receiver.size();
        ansc.resize(n, vector<pi >(mx));
        for (ll i = 0; i < n; i++) ansc[i][0] = {receiver[i], receiver[i]};
        for (ll bt = 1; bt < mx; bt++) {
            for (ll i = 0; i < n; i++) {
                ll prevTotal = ansc[i][bt - 1].second;
                ll parent = ansc[i][bt - 1].first;
                ll total = prevTotal + ansc[parent][bt-1].second;
                ll currentParent = ansc[parent][bt - 1].first;
                ansc[i][bt] = {currentParent, total};
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) ans = max(ans, solve(i, k));
        return ans;
    }
    ll solve(ll idx, ll k) {
        ll res = idx;
        for (ll bt = mx - 1; bt >= 0; bt--) {
            if (((1ll << bt) & k) != 0) {
                res += ansc[idx][bt].second;
                idx = ansc[idx][bt].first;
            }
        }
        return res;
    }
};