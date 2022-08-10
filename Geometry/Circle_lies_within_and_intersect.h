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
// cout << setprecision(6) << fixed;


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
#define tp tuple<ll, ll, ll, ll>
vector<vector<ll>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // left, down, right, up
vector<vector<ll>> dirsDiag = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};


typedef complex<long double> P;
#define X real()
#define Y imag()
// Distance between two points
long double distanceBtwTwoPoints(P a, P b) {
    return abs(b - a);
}
// Angle to the x-axis in radians
long double angleToXAxis (P a) {
    return arg(a);
}

#define ll long long
#define pi pair<ll, ll>

// cross product given three points.
ll crossProduct(pi &a, pi &b, pi &c) {
    return ((a.first - b.first) * (c.second - b.second)) - ((a.second - b.second) * (c.first - b.first));
}

// Question: https://atcoder.jp/contests/abc259/tasks/abc259_d
class Solution {
public:
    ll n;
    vector<ll> seen; // 0-unseen, 1-seen, 2-endPoint
    vector<vector<ll>> adj;
    ll equal(ll x1, ll y1, ll x2, ll y2, ll r) {
        return r * r == dist(x1, y1, x2, y2);
    }
    ll dist(ll x1, ll y1, ll x2, ll y2) {
        ll a = x1 - x2, b = y1 - y2;
        return (a * a + b * b);
    }
    void run() {
        cin >> n;
        seen.resize(n);
        adj.resize(n);
        ll sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        vector<vector<ll>> arr(n);
        vector<ll> dq;
        for (ll i = 0; i < n; i++) {
            ll x, y, r; cin >> x >> y >> r;
            arr[i] = {x, y, r};
            if (equal(sx, sy, x, y, r))
                dq.push_back(i);
            if (equal(ex, ey, x, y, r))
                seen[i] = 2;
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                ll a = i, b = j;
                if (arr[a][2] < arr[b][2]) swap(a, b);
                ll centerDiff = dist(arr[a][0], arr[a][1], arr[b][0], arr[b][1]);
                ll radDiff = (arr[a][2] - arr[b][2]) * (arr[a][2] - arr[b][2]);
                ll radAdd = (arr[a][2] + arr[b][2]) * (arr[a][2] + arr[b][2]);
                bool lieWithin = centerDiff < radDiff;
                bool noIntersect = centerDiff > radAdd;
                if (lieWithin || noIntersect) continue;
                connect(i, j);
            }
        }

        while (!dq.empty()) {
            ll idx = dq.back();
            dq.pop_back();
            if (seen[idx] == 2) {
                print("Yes"); return;
            }
            for (auto child: adj[idx]) {
                if (seen[child] == 1) continue;
                if (seen[child] == 2) {
                    print("Yes"); return;
                }
                seen[child] = 1;
                dq.push_back(child);
            }
        }
        print("No");
    }
    void connect(ll i, ll j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
};

int main() {
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}
