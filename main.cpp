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
    void run() {
    }
};

class UnionFind {
    /*
    UnionFind or DisjollSet data-structure with Path compression. Zero indexed.
    Initialize:
            UnionFind(n)
            Methods:
    unify(p, q)        # unify p and q
    connected(p, q)    # is p connected to q (return bool)
    find(p)            # find the parent of q
    getSize(p)         # return the group size of p
    */
private:
    ll size = 0;
    ll* sizes;
    ll* parents;
public:
    ll groups;
    UnionFind(ll n) {
        size = n;
        groups = n;
        sizes = new ll[size];
        parents = new ll[size];
        for(ll i=0; i < size; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] sizes;
        delete [] parents;
    }

    ll find(ll p) {
        assert(p >= 0 && p < size);
        ll root = p;
        while (root != parents[root])
            root = parents[root];

        // path compression
        while (p != root) {
            ll tmp = parents[p];
            parents[p] = root;
            p = tmp;
        }
        return root;
    }
    ll getSize(ll p) {
        return sizes[find(p)];
    }

    bool connected(ll p, ll q){
        return find(p) == find(q);
    }
    bool unify(ll p, ll q) {
        assert(p >= 0 && p < size);
        assert(q >= 0 && q < size);
        ll root1 = find(p);
        ll root2 = find(q);
        if (root1 == root2) return false;
        if (sizes[root1] < sizes[root2]){
            parents[root1] = root2;
            sizes[root2] += sizes[root1];
        } else {
            parents[root2] = root1;
            sizes[root1] += sizes[root2];
        }
        groups -= 1;
        return true;
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
        UnionFind uf(n);
        for (auto &x: edges) {
            ll a = x[0], b = x[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }
        ll mxVal = *max_element(vals.begin(), vals.end());
        valNodes.resize(mxVal + 1);
        for (ll i = 0; i < n; i++) valNodes[vals[i]].push_back(i);
        ll ans = 0;
        for (ll i = 0; i <= mxVal; i++) {
            if (valNodes[i].empty()) continue;
            for (auto node: valNodes[i]) {
                seen[node] = 1;
                for (auto child: adj[node]) if (seen[child]) uf.unify(node, child);
            }
            map<ll, ll> cnt;
            for (auto node: valNodes[i]) cnt[uf.find(node)]++;
            for (auto x: cnt) {
                ans += (x.second * (x.second + 1)) /2;
            }
        }
        return ans;
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
