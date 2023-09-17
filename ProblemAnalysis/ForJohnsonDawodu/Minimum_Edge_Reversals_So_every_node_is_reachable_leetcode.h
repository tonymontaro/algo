#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>
ll MOD = 1e9 + 7;

class Solution {
public:
    vector<vector<ll>> adj;
    map<pi, ll> dir;
    vector<pi> reversed;
    ll total = 0;
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (ll i = 0; i < edges.size(); i++) {
            ll a = edges[i][0], b = edges[i][1];
            dir[{a, b}] = 1;
            dir[{b, a}] = -1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        reversed.resize(n);
        compute(0, -1, {0, 0});
        vector<int> ans(n);
        for (ll i = 0; i < n; i++) {
            int rest = total - reversed[i].second;
            int toRoot = reversed[i].first - reversed[i].second;
            ans[i] = rest + toRoot;
        }
        return ans;
    }
    void compute(ll node, ll parent, pi rev) {
        reversed[node] = rev;
        for (auto child: adj[node]) {
            if (child == parent) continue;
            pi rv = rev;
            rv.first++;
            if (dir[{node, child}] == -1) {
                rv.second++;
                total++;
            }
            compute(child, node, rv);
        }
    }
};