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

// Given the probability of success = p
// => expected number of trials until the first success = 1/p
// article: https://atcoder.jp/contests/abc194/editorial/864
class Solution {
public:
    ll rlen, clen;
    vector<vector<ll>> grid;
    void run() {
        cin >> rlen >> clen;
        grid.resize(rlen, vector<ll>(clen));
        for (ll i = 0; i < rlen; i++) {
            string s; cin >> s;
            for (ll j = 0; j < clen; j++) {
                if (s[j] == '.') grid[i][j] = 0;
                else grid[i][j] = 1;
            }
        }
        ll res = 0;
        for (ll i = 2; i < 5; i++) {
            res += solve(i);
            rotate(grid);
        }
        res += solve(5);
        print(res);
    }
    ll solve(ll d) {
        print("start solve");
        rlen = grid.size(), clen = grid[0].size();
        ll res = 0;
        for (ll r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; ++c ) {
                if (grid[r][c] > 0 && grid[r][c] != d) {
                    res++;
                    while (r < rlen && grid[r][c] > 0) {
                        grid[r][c] = d;
                        r++;
                    }
                }
            }
        }
        for (auto &x: grid) printArr(x);
        print("========s====");
        return res;
    }
    void rotate(vector<vector<ll>>& matrix) {
        print("start rotate");
        ll row = matrix.size(), col = matrix[0].size();
        print2(row, col);
        vector<vector<ll>> ans(col, vector<ll>(row));
        for (ll r = 0; r < row; r++) {
            for (ll c = 0; c < col; c++) {
                ll cc = row - 1 - r;
                ll rr = c;
                ans[rr][cc] = matrix[r][c];
            }
        }
        swap(grid, ans);
        print("end rotate");
    }
};

int main(){
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}
