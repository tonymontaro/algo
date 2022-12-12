#include <bits/stdc++.h>
//#include <atcoder/all>
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
//        print3(y, res, x);
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


class Solver {
public:
    void run() {
        readInput();
    }
    ll n;
    ll rlen, clen, row, col;
    string s;
    void readInput() {
//        useFile();
        int cases;
        cin >> cases;
        for (int case_id = 1; case_id < cases + 1; case_id++) {
            cin >> n;
            cin >> rlen >> clen >> row >> col;
            cin >> s;
            main();

            cout << "Case #" << case_id << ": " << row << " " << col << endl;
        }
    }

    ll answer;
    void main() {
        map<ll, map<ll, ll>> rows;
        map<ll, map<ll, ll>> cols;
        rows[row][col] = col;
        cols[col][row] = row;
        for (ll i = 0; i < n; i++) {
            if (s[i] == 'E' || s[i] == 'W') {
                col = getCol(rows, s[i]);
            } else {
                row = getRow(cols, s[i]);
            }
            setCol(rows);
            setRow(cols);
//            print3(row, col, "====");
        }
    }
    ll getCol(map<ll, map<ll, ll>> &rows, char dir) {
        map<ll, ll> &mp = rows[row];
        auto it = mp.lower_bound(col);
        if (it == mp.end() || it->first > col) it--;
        if (dir == 'E') return it->second + 1;
        else return it->first - 1;
    }
    void setCol(map<ll, map<ll, ll>> &rows) {
        map<ll, ll> &mp = rows[row];
        auto it = mp.lower_bound(col);
        ll last = it->second;
        if (it->first == col + 1) {
            mp.erase(it);
            mp[col] = last;
        } else {
            mp[col] = col;
        }
        auto prev = mp.lower_bound(col);
        if (prev != mp.begin()) {
            last = prev->second;
            prev--;
            if (prev->second == col - 1) {
                ll first = prev->first;
                mp.erase(col);
                mp.erase(prev);
                mp[first] = last;
            }
        }
//        for (auto &x: mp) print2(x.first, x.second);
    }
    ll getRow(map<ll, map<ll, ll>> &cols, char dir) {
        map<ll, ll> &mp = cols[col];
        auto it = mp.lower_bound(row);
        if (it == mp.end() || it->first > row) it--;
        if (dir == 'S') return it->second + 1;
        else return it->first - 1;
    }
    void setRow(map<ll, map<ll, ll>> &cols) {
        map<ll, ll> &mp = cols[col];
        auto it = mp.lower_bound(row);
        ll last = it->second;
        if (it->first == row + 1) {
            mp.erase(it);
            mp[row] = last;
        } else {
            mp[row] = row;
        }
        auto prev = mp.lower_bound(row);
        if (prev != mp.begin()) {
            last = prev->second;
            prev--;
            if (prev->second == row - 1) {
                ll first = prev->first;
                mp.erase(row);
                mp.erase(prev);
                mp[first] = last;
            }
        }
//        for (auto &x: mp) print2(x.first, x.second);
    }

};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ll n = heights.size();
        ll ans = 0;
        vector<pair<ll, ll>> stk;
        for (ll i = 0; i < heights.size(); i++) {
            ll idx = i;
            ll val = heights[i];
            while (!stk.empty() && val <= stk.back().first) {
                ans = max(ans, (stk.back().first * (i - stk.back().second)));
                idx = stk.back().second;
                stk.pop_back();
            }
            stk.push_back({val, idx});
        }
        for (ll i = 0; i < stk.size(); i++) {
            ans = max(ans, (stk[i].first * (n - stk[i].second)));
        }
        return ans;
    }
};

int main(){
    fastInputOutput();


    Solver sol;
//    sol.run();


    return 0;
}
