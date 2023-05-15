#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>

// DFS/recursive version: pass in adjacency list
class TopSort{
public:
    vector<int> seen;
    bool impossible = false;
    vector<int> ans;
    vector<int> solve(int n, vector<vector<int>> &adj) {
        seen = vector<int>(n + 1);
        for (int i = 1; i < n + 1; i++)
            dfs(i, adj);
        if (impossible) return {};
        else {
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
    void dfs(int node, vector<vector<int>> &adj) {
        if (seen[node] == 2 || impossible) return;
        if (seen[node] == 1) {
            impossible = true;
            return;
        }
        seen[node] = 1;
        for (auto child: adj[node]) {
            dfs(child, adj);
        }
        seen[node] = 2;
        ans.push_back(node);
    }
};

// iterative version: pass in edges array (b, a): a before b i.e. b -> a
class TopologicalSort {
public:
    vector<ll> run(ll n, vector<vector<int>> edges) {
        vector<ll> cnt(n + 1);
        queue<ll> que;
        vector<vector<ll>> adj(n + 1);
        for (auto &e: edges) {
            adj[e[1]].push_back(e[0]);
            cnt[e[0]]++;
        }
        for (ll i = 1; i < n+1; i++) if (cnt[i] == 0) que.push(i);
        vector<ll> ans;
        while (!que.empty()) {
            ll node = que.front();
            que.pop();
            ans.push_back(node);
            for (auto parent:  adj[node]) {
                cnt[parent]--;
                if (cnt[parent] == 0) que.push(parent);
            }
        }
        if (ans.size() == n) return ans;
        return {};
    }
};