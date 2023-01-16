#include <bits/stdc++.h>
using namespace std;

//#include <atcoder/all>

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


class Solution {
public:
    void run() {
/*
Question: https://atcoder.jp/contests/abc189/tasks/abc189_e
Helpful vid: Concept of unit vectors and scalars: https://www.youtube.com/watch?v=k7RM-ot2NWY&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab&index=2
Imagine the effect of the rotations and flips on the origin (0, 0), and the x & y unit vectors (1,0), (0, 1).
We can consider the original points as scalars for the unit vectors. For example the point (2, 3) scales the x unit vector
by 2 and the y unit vector by 3.
By keeping track of the final effect on the origin, x, and y unit vectors; we can compute the final positions of the original scalar points.
*/
        ll n; cin >> n;
        vector<pi > points(n);
        for (ll i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
        ll m; cin >> m;
        vector<pi> operations(m);
        for (ll i = 0; i < m; i++) {
            cin >> operations[i].first;
            if (operations[i].first == 3 || operations[i].first == 4)
                cin >> operations[i].second;
        }
        vector<pi> arr = {{0, 0}, {1, 0}, {0, 1}}; // origin and unit x, y vectors
        vector<vector<pi>> finalEffect;
        finalEffect.push_back(arr);
        for (auto op: operations) {
            if (op.first == 1) {
                for (ll i = 2; i >= 0; i--) arr[i] = rotateAntiClockwise(arr[i], 270);
            }
            if (op.first == 2) {
                for (ll i = 2; i >= 0; i--) arr[i] = rotateAntiClockwise(arr[i], 90);
            }
            if (op.first == 3) {
                for (ll i = 2; i >= 0; i--) arr[i] = translateX(arr[i], op.second);
            }
            if (op.first == 4) {
                for (ll i = 2; i >= 0; i--) arr[i] = translateY(arr[i], op.second);
            }
            finalEffect.push_back(arr);
        }

        ll q; cin >> q;
        for (ll i = 0; i < q; i++) {
            ll opNum, idx; cin >> opNum >> idx;
            idx--;
            // scale the unit vectors in finalEffect
            pi X = finalEffect[opNum][1], Y = finalEffect[opNum][2], origin = finalEffect[opNum][0];
            ll xScaler = points[idx].first;
            ll yScaler = points[idx].second;
            ll x = xScaler * (X.first - origin.first) + yScaler * (Y.first - origin.first); // note: one of the diff should be zero.
            ll y = xScaler * (X.second - origin.second) + yScaler * (Y.second - origin.second); // same here
            print2((x + origin.first), (y + origin.second));

        }
    }
    lb degreesToRad(lb deg) {
        return (deg * M_PI) / 180;
    }
    pi rotateAntiClockwise(pi val, ll dd) {
        ll x = val.first, y = val.second;
        lb d = degreesToRad(dd);
        lb x1 = x * cos(d) - y * sin(d);
        lb y1 = x * sin(d) + y * cos(d);
        return {round(x1), round(y1)};
    }
    pi translateX(pi val, ll axis) {
        ll x = val.first, y = val.second;
        ll diff = axis -  x;
        return {(diff + axis), y};
    }
    pi translateY(pi val, ll axis) {
        ll x = val.first, y = val.second;
        ll diff = axis -  y;
        return {x, (diff + axis)};
    }
};
int main(){
    fastInputOutput();
//    usefile();
//    printArr(primes);
    Solution sol;
    sol.run();

    return 0;
}
