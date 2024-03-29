#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }


#define usefile()                                                     \
  ifstream cin("../test_input.txt"); /*ofstream cout("../out.txt");*/ \
  std::cin.rdbuf(cin.rdbuf());                                        \
  std::cout.rdbuf(cout.rdbuf())

string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl

template <typename T>
void printArr(T &arr) {
    for (auto x : arr) cout << x << " ";
    cout << endl;
}
template <typename T>
void printArr(vector<vector<T>> &arr) {
    for (auto &x : arr) printArr(x);
}

string bin_string(long long num) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res += (num & 1) + '0';
        num >>= 1;
    }
    reverse(res.begin(), res.end());
    print(res);
    return res;
}

#define ll long long
#define lb long double
const int INF = (int)2e9;
const ll LINF = (ll)4e18;
ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1;
    x = x % p;
    if (x == 0) return 0;  // In case x is divisible by p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll popcount(ll num) { return __builtin_popcount((unsigned int)num); }

ll hashNum(ll a) { return a * (a + 1346) * (a + 9185); }
void extendVector(vector<ll> &v, vector<ll> &other) {
    for (auto val : other) v.push_back(val);
}
map<ll, ll> coordCompress(vector<ll> &arr) {
    set<ll> st(arr.begin(), arr.end());
    map<ll, ll> mp;
    ll idx = 1;
    for (auto &x : st) mp[x] = idx++;
    return mp;
}

#define tp tuple<ll, ll, ll>
vector<vector<ll>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // right, down, left, up
vector<vector<ll>> dirsDiag = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                               {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
ll strHashMult = 911382323;
ll strHashMod = 972663749;

// using lm = ::atcoder::modint1000000007;
#define ll long long
#define pi pair<ll, ll>
// get the bit set value at index idx
#define bit(num, idx) ((num >> idx) & 1)
void printArr(vector<pi> &arr) {
    for (auto x : arr) cout << "(" << x.first << "," << x.second << ") ";
    cout << endl;
}
ll Combination(ll n, ll k) {
    long double res = 1;
    for (int i = 1; i <= k; ++i) res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}
vector<string> splitWord(string &s) {
    istringstream iss(s, istringstream::in);
    vector<string> words;
    string word;
    while (iss >> word) words.push_back(word);
    return words;
}

// using lm = ::atcoder::modint1000000007;
// using lm = ::atcoder::modint998244353;


#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>
ll MOD = 1e9 + 7;

// Question: https://atcoder.jp/contests/abc249/tasks/abc249_e
class Solution {
public:
    ll n, mod;
    void run() {
        cin >> n >> mod;
        vector<vector<ll>> dp(3010, vector<ll>(3010));
        vector<vector<ll>> sm(3010, vector<ll>(3010));
        for (ll slen = 1; slen <= n; slen++) {
            dp[slen][getSize(slen)] = 26;
        }
        for (ll sLen = 1; sLen <= n; sLen++){
            for (ll tLen = 1; tLen <= n; tLen++) {
                for (ll k = 2; k <= 5; k++) {
                    if (tLen - k < 0) break;
                    auto minMax = getMinMax(k);
                    if (minMax.first > sLen) break;
                    ll lo = minMax.first;
                    ll hi = min(sLen, minMax.second);

                    ll subtract = hi == sLen ? 0 : sm[sLen - hi - 1][tLen - k];
                    dp[sLen][tLen] += ((sm[sLen - lo][tLen - k] - subtract + mod) * 25) % mod;
                }
                sm[sLen][tLen] = (sm[sLen][tLen] + dp[sLen][tLen]) % mod;
                sm[sLen + 1][tLen] = (sm[sLen + 1][tLen] + sm[sLen][tLen]) % mod;
            }
        }
        ll ans = 0;
        for (ll tLen = 1; tLen < n; tLen++) {
            ans = (ans + dp[n][tLen]) % mod;
        }
        print(ans);
    }
    pi getMinMax(ll k) {
        if (k == 2) return {1, 9};
        if (k == 3) return {10, 99};
        if (k == 4) return {100, 999};
        return {1000, 9999};
    }
    ll getSize(ll num) {
        if (num < 10) return 2;
        if (num < 100) return 3;
        if (num < 1000) return 4;
        return 5;
    }
};

int main(){
    fastInputOutput();
//    usefile();

    Solution sol;
    sol.run();

    return 0;
}
