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
int block_size;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

class MoAlgorithm {
public:
    vector<int> arr;
    vector<int> cnt;
    int ans = 0;
    void remove(int idx) {
        int val = arr[idx];
        cnt[val] -= 1;
        if (cnt[val] % 2 == 1) ans--;
    }
    void add(int idx) {
        int val = arr[idx];
        cnt[val] += 1;
        if (cnt[val] % 2 == 0) ans++;
    }

    void mo_s_algorithm(vector<Query> &queries) {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());

        int cur_l = queries[0].l;
        int cur_r = queries[0].l-1;
        // invariant: data structure will always reflect the range [cur_l, cur_r]
        for (Query q : queries) {
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            answers[q.idx] = ans;
        }
        for (auto ans: answers) print(ans);
    }
};

// Problem: https://atcoder.jp/contests/abc242/tasks/abc242_g
// Great vid: https://www.youtube.com/watch?v=BJhzd_VG61k
// Helpful article: https://cp-algorithms.com/data_structures/sqrt_decomposition.html#mos-algorithm
// Submission: https://atcoder.jp/contests/abc242/submissions/32488965
int main() {
    fastInputOutput();

    ll n; cin >> n;
    block_size = sqrt(n);
    MoAlgorithm solver;
    solver.arr = vector<int>(n);
    solver.cnt = vector<int>(100001);
    for (ll i = 0; i < n; i++) cin >> solver.arr[i];
    ll q; cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int left, right; cin >> left >> right;
        queries[i].l = left-1;
        queries[i].r = right-1;
        queries[i].idx = i;
    }
    solver.mo_s_algorithm(queries);

    return 0;
}
