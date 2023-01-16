#include <bits/stdc++.h>
using namespace std;


void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define usefile() ifstream cin("../test_input.txt"); /*ofstream cout("../out.txt");*/ std::cin.rdbuf(cin.rdbuf()); std::cout.rdbuf(cout.rdbuf())

string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl

template <typename T>
void printArr(T &arr) {
    for (auto x: arr) cout << x << " ";
    cout << endl;
}
template <typename T>
void printArr(vector<vector<T>> &arr) {
    for (auto &x: arr) printArr(x);
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

ll popcount(ll num) {
    return __builtin_popcount((unsigned int) num);
}
ll MOD = 1e9 + 7;

ll hashNum(ll a) {
    return a * (a + 1346) * (a + 9185);
}
void extendVector(vector<ll> &v, vector<ll> &other) {
    for (auto val: other) v.push_back(val);
}
map<ll, ll> coordCompress(vector<ll> &arr) {
    set<ll> st(arr.begin(), arr.end());
    map<ll, ll> mp;
    ll idx = 1;
    for (auto &x: st) mp[x] = idx++;
    return mp;
}

#define tp tuple<ll, ll, ll>
vector<vector<ll>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // left, down, right, up
vector<vector<ll>> dirsDiag = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

//using lm = ::atcoder::modint998244353;
//using lm = ::atcoder::modint1000000007;
#define ll long long
#define pi pair<ll, ll>
// get the bit set value at index idx
#define bit(num, idx) ((num >> idx) & 1)
void printArr(vector<pi> &arr) {
    for (auto x: arr) cout << "(" << x.first << "," << x.second << ") ";
    cout << endl;
}
ll Combination(ll n, ll k) {
    long double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}
vector<string> splitWord(string &s) {
    istringstream iss(s, istringstream::in);
    vector<string> words;
    string word;
    while (iss >> word) words.push_back(word);
    return words;
}

class Solution2 {
public:
    map<string, string> adj;
    set<string> seen;
    void run() {
        ll n; cin >> n;
        vector<string> arr;
        for (ll i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            adj[a] = b;
            arr.push_back(a);
        }
        for (ll i = 0; i < n; i++) {
            string s = arr[i];
            if (seen.find(s) == seen.end()) {
                set<string> cur;
                dfs(s, cur);
            }
        }
        if (valid) print("Yes");
        else{
            print("No");}
    }
    bool valid = true;
    void dfs(string &node, set<string> &cur) {
//        print2(node, "===");

        if (cur.find(node) != cur.end()) {
            valid = false; return;
        }
        if (!valid || seen.find(node) != seen.end()) return;
        seen.insert(node);
        cur.insert(node);
        if (adj.find(node) != adj.end())
            dfs(adj[node], cur);
    }
};

class Solution {
public:
    vector<set<ll>> adj;
    vector<vector<ll>> valNodes;
    vector<ll> seen;
    ll n;
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        n = vals.size();
        adj.resize(n );
        seen.resize(n );
        for (auto &x: edges) {
            ll a = x[0], b = x[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }
        ll mxVal = *max_element(vals.begin(), vals.end());
        valNodes.resize(mxVal + 1);
        for (ll i = 0; i < n; i++) valNodes[vals[i]].push_back(i);
        ll ans = 0;
        print2(n, count(3, -1));
        for (ll i = 0; i <= mxVal; i++) {
            for (auto node: valNodes[i]) {
                if (seen[node]) continue;
                print("-----------");
                vector<ll> holder;
                ll res = dfs(node, -1, holder, vals);
                ans += ((res + 1) * res) / 2;
                print2("holder size:   ", holder.size());
//                printArr(holder);
//                return 0;
                if (holder.empty()) continue;
                ll a = holder[0];
                for (ll j = 1; j < holder.size(); j++) {
                    ll b = holder[j];
                    adj[a].insert(b);
                    adj[b].insert(a);
                }
                print2(count(3, -1), "---------");
            }
        }
        return ans;
    }
    ll dfs(ll node, ll parent, vector<ll> &holder, vector<int>& vals) {
        print2(vals[node], node);
        ll res = 1;
        seen[node] = 1;
        for (auto child: adj[node]) {
            if (child == parent) continue;
            if (vals[child] > vals[node]) {
//                for (auto x: adj[child]) cout << "." << x << ".";
//                cout << endl;
                adj[child].erase(node);
//                for (auto x: adj[child]) cout << "." << x << ".";
//                cout << endl;
                holder.push_back(child);
            } else {
                res += dfs(child, node, holder, vals);
            }
        }

        return res;
    }
    ll count(ll node, ll parent) {
        ll res = 1;
        for (auto child: adj[node]) if (child != parent) res += count(child, node);
        return res;
    }
};

int main(){
    fastInputOutput();
//    usefile();

    Solution sol;
    vector<int> vals = {1,4,11,19,14,11,12,18,9,15,18,9,11,1,18,8,10,13,3,17,1,10,11,15,11,19,2};
    vector<vector<int>> edges = {{0,1},{0,2},{3,0},{4,3},{0,5},{2,6},{7,4},{4,8},{9,2},{10,0},{3,11},{1,12},{5,13},{6,14},{6,15},{16,0},{14,17},{12,18},{19,6},{20,17},{14,21},{12,22},{23,20},{24,11},{25,15},{26,7}};
    print(sol.numberOfGoodPaths(vals, edges));
//    sol.run();

    return 0;
}
