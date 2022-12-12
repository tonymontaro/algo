#include <bits/stdc++.h>
//#include <atcoder/all>
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
    return __builtin_popcount((unsigned int) num);
//    ll res = 0;
//    while (num > 0) { res += (1 & num); num >>= 1; }
//    return res;
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

ll Combination(ll n, ll k) {
    long double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}

namespace LinearSieve {
    vector<ll> getPrimes(ll N) {
        vector<ll> lp(N+1);
        vector<ll> pr;

        for (int i=2; i <= N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
                lp[i * pr[j]] = pr[j];
            }
        }
        return pr;
    }
}

class Solver {
public:
    void run(vector<ll> &primes) {
        ll n; cin >> n;
        vector<ll> arr(n);
        map<ll, ll> cnt;
        bool pairwise = true;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];

            ll num = arr[i];
            if (!pairwise) continue;
            for (auto p: primes) {

                if (num % p == 0) {
                    cnt[p]++;
                    if (cnt[p] > 1) pairwise = false;
                }
                while (num % p == 0) {
                    if (num != p && num != 1) {
                        cnt[num]++;
                        if (cnt[num] > 1) pairwise = false;
                    }
                    num = num / p;
                }
                if (num == 1) break;
            }
            if (num != 1) {
                cnt[num]++;
                if (cnt[num] > 1) pairwise = false;
            }
        }

        if (pairwise) print("NO");
        else print("YES");
    }
};


int main(){
    fastInputOutput();
//    usefile();

    int cases;
    cin >> cases;
    ll mx = 1e9;
    mx = sqrt(mx);
    auto primes = LinearSieve::getPrimes(mx);
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        Solver sol;
        sol.run(primes);
    }

    return 0;
}
