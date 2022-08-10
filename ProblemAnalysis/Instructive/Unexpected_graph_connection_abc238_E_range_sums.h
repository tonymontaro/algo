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
string bin_string(long long num) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res += (num & 1) + '0';
        num >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
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
void extendVector(vector<ll> &v, vector<ll> &other) {
//    v.reserve(v.size() + distance(other.begin(),other.end()));
//    v.insert(v.end(),other.begin(),other.end());
    for (auto val: other) v.push_back(val);
}
#define tp tuple<ll, ll, ll, ll>

#define ll long long
#define pi pair<long, long>
// get the bit set value at index idx
#define bit(num, idx) ((num >> idx) & 1)

class Solution {
public:
    ll n, q;
    vector<vector<ll>> adj;
    void run() {
        cin >> n >> q;
        adj.reserve(n + 1);
        seen.reserve(n + 1);
        for (ll i = 0; i < q; i++) {
            ll a, b; cin >> a >> b;
            adj[b].push_back(a - 1);
            adj[a - 1].push_back(b);
        }
        dfs(0);
        print((seen[n] ? "Yes" : "No"));
    }
    vector<ll> seen;
    void dfs(ll node) {
        if (seen[node]) return;
        seen[node] = 1;
        for (auto &child: adj[node]) dfs(child);
    }
};

int main(){
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}

