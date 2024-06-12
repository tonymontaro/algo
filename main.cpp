// start date (2024 gravel b-plan): 11 June, 2024
#include <bits/stdc++.h>

//#include <atcoder/all>
//using namespace atcoder;
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }

#define usefile()                                                     \
  ifstream cin("../test_input.txt"); /*ofstream cout("../out.txt"); */ \
  std::cin.rdbuf(cin.rdbuf());                                        \
  std::cout.rdbuf(cout.rdbuf())

string delim = " ";
#define print(x) cout << setprecision(16) << fixed << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl
#define ll long long
#define lb long double
#define pi pair<ll, ll>

template <typename T>
void printArr(T &arr) {
    for (auto x : arr) cout << x << " ";
    cout << endl;
}
void printArr(vector<pair<long long, string>> &arr) {
    for (auto x : arr) cout << " (" << x.first << ", " << x.second << ") ";
    cout << endl;
}
void printArr(deque<tuple<long long, long long, long long>> &arr) {
    long long a, b, c;
    for (auto x : arr) {
        tie(a, b, c) = x;
        cout << " (" << a << ", " << b << ", " << c << ") ";
    }
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
//    print(res);
    return res;
}
string bin_string_fixed(long long num, int sz = 10) {
//    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        res += (num & 1) + '0';
        num >>= 1;
    }
    while (res.size() < sz) res.push_back('0');
//    print(res);
    return res;
}


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

ll popcount(ll num) { return __builtin_popcountll(num); }
ll maxSetBit(ll num) {
    assert(num >= 0);
    for (ll i = 0; i < 64; i++) {
        num /= 2;
        if (num == 0) return i;
    }
    return -1;
}

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

vector<vector<ll>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // right, down, left, up
vector<vector<ll>> dirsDiag = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                               {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
ll strHashMult = 911382323;
ll strHashMod = 972663749;

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
//using lm = ::atcoder::modint998244353;

#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>
#define tpd tuple<ll, ll, ll, ll>;
ll MOD = 1e9 + 7;
ll MX = 1e17;


class Solution {
public:
    ll n, m, q, k;
    ll rlen, clen;
    void run() {
        print("ready");
    }
};


int main() {
    fastInputOutput();
//    usefile();

    Solution sol;
    sol.run();

    return 0;
}

