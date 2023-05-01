#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>

class Centroid {
public:
    ll get(vector<vector<ll>> &adj, ll root, ll n_) {
        n = n_;
        kids.resize(n + 1);
        dfs(root, -1, adj);
        return solve(root, -1, adj);
    }
private:
    ll n;
    vector<ll> kids;
    ll dfs(ll node, ll parent, vector<vector<ll>> &adj) {
        ll res = 1;
        for (auto child : adj[node]) {
            if (child == parent) continue;
            res += dfs(child, node, adj);
        }
        kids[node] = res;
        return res;
    }
    ll solve(ll node, ll parent, vector<vector<ll>> &adj) {
        for (auto child: adj[node]) {
            if (child == parent) continue;
            if (kids[child] > (n/2)) return solve(child, node, adj);
        }
        return node;
    }
};