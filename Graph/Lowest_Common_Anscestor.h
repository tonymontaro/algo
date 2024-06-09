#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>

// Learn it: https://www.youtube.com/watch?v=oib-XsjFa-M
class TreeAncestor {
public:
    // Initialize with zero indexed nodes, and parent[root] = -1
    vector<vector<ll>> ansc; // ansc[node][i] -> (2^i)th parent of node.
    vector<ll> depth;
    ll n;
    ll mx = 16; // LOG(n)
    TreeAncestor(ll nn, vector<ll>& parent, vector<ll> &dpth) {
        swap(dpth, depth);
        n = nn;
        mx = log2(n + 1);
        ansc.resize(n + 2, vector<ll>(mx + 2, -1));
        for (ll i = 0; i < n; i++) ansc[i][0] = parent[i];
        for (ll i = 1; i <= mx; i++) {
            for (ll node = 0; node < n; node++) {
                ll p = ansc[node][i - 1];
                if (p == -1) ansc[node][i] = -1;
                else ansc[node][i] = ansc[p][i - 1];
            }
        }
    }
    ll getKthAncestor(ll node, ll k) {
        for (ll i = mx; i >= 0; i--) {
            if (((1 << i) & k) != 0) node = ansc[node][i];
            if (node == -1) return -1;
        }
        return node;
    }
    ll commonAncestor(ll a, ll b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = getKthAncestor(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (ll i = mx; i >= 0; i--) {
            if (ansc[a][i] != ansc[b][i]) {
                a = ansc[a][i];
                b = ansc[b][i];
            }
        }
        return ansc[a][0];
    }
};

// Nice problem involving this and segment tree: https://atcoder.jp/contests/abc294/tasks/abc294_g
// Solution: https://atcoder.jp/contests/abc294/submissions/51661563

// Example problem: https://www.spoj.com/problems/LCASQ/ (solution below)
class Solution {
public:
    ll n, m, q, x;
    vector<ll> depth;
    vector<ll> parent;
    vector<vector<ll>> adj;
    void run() {
        cin >> n;
        parent.resize(n);
        depth.resize(n);
        adj.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> m;
            for (ll j = 0; j < m; j++) {
                ll b; cin >> b;
                adj[i].push_back(b);
                parent[b] = i;
            }
        }
        dfs(0, 0);
        TreeAncestor solver(n, parent, depth);
        cin >> q;
        for (ll i = 0; i < q; i++) {
            ll a, b; cin >> a >> b;
            cout << solver.commonAncestor(a, b) << endl;
        }
    }
    void dfs(ll node, ll d) {
        depth[node] = d;
        for (auto child: adj[node]) dfs(child, d + 1);
    }
};
