#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define useFile() ifstream cin("../test_input.txt"); ofstream cout("../out.txt")
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl


template <typename T>
void printArr(T &arr) {
    for (auto x: arr) cout << x << " ";
    cout << endl;
}

#define ll long long
#define lb long double
const int INF = (int)2e9;
const ll LINF = (ll)4e18;
ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1; x = x % p;  if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
// same as count = __builtin_popcount((unsigned int) num);
ll popcount(ll num) {
    ll res = 0;
    while (num > 0) { res += (1 & num); num >>= 1; }
    return res;
}
ll MOD = 1e9 + 7;

ll hashNum(ll a) {
    return a * (a + 1346) * (a + 9185);
}
#define tp tuple<ll, ll, ll, ll>

#define ll long long
class Node {
public:
    vector<Node*> children;
    ll val;
    Node(ll v) : val(v) {
    }
    Node(){}
};
class Solution {
public:
    vector<Node> nodes;
    vector<vector<ll>> adj;
    vector<bool> seen;
    vector<vector<pair<ll, ll>>> queries;
    void run() {
        ll n, q; cin >> n >> q;
        nodes.resize(n + 1);
        queries.resize(n + 1);
        seen.resize(n + 1, false);

        for (ll i = 1; i <= n; i++) {
            ll v; cin >> v;
            nodes[i].val = v;
        }
        adj.resize(n + 1);
        for (ll i = 0; i < n - 1; i++) {
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        rootAtOne(1);

        for (ll i = 0; i < q; i++) {
            ll node, k; cin >> node >> k;
            queries[node].push_back({k, i});
        }
    }
    void rootAtOne(ll node) {
        seen[node] = true;
        for (auto child: adj[node]) {
            if (seen[child]) continue;
            nodes[node].children.push_back(&nodes[child]);
            rootAtOne(child);
        }
    }
};

int main() {
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}
