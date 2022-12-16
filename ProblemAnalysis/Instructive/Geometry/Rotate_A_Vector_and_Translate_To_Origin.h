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


class Solution {
public:
    void run() {
        // Question: https://atcoder.jp/contests/abc197/tasks/abc197_d
        // Helpful vid: https://www.youtube.com/watch?v=Rv5D_GQIIek
        // Formula for rotating a vector in 2D: https://matthew-brett.github.io/teaching/rotation_2d.html
        // Assuming x, y represents a vector at that point with 0, 0 as the origin, we can use the formula below to rotate the vector by R degrees (in radian). The new vector will be x1, y1
        // x1 = cos(R) * x - sin(R) * y;
        // y1 = sin(R) * x + cos(R) * y;
        // we can inscribe the polygon within a circle. The radius is easy to find from the input.
        // using the center of the circle as the origin; x0, y0 is a vector which we will rotate by 360/n or (2 * pi)/n to get to x1, y1
        // 360 / n because each vertex of the regular n sided polygon divides the circle equally.
        lb n; cin >> n;
        lb x0, y0; cin >> x0 >> y0;
        lb xh, yh; cin >> xh >> yh;
        lb cx = (x0 + xh) / 2;
        lb cy = (y0 + yh) / 2;
        // let's assume x0, y0 is a vector with cx, cy as origin. Now translate this vector to x, y with 0,0 as origin
        lb x = x0 - cx;
        lb y = y0 - cy;
        lb p = M_PI;
        // computing x1, y1 (with 0,0 as origin) using the formula
        lb x1 = (cos((2 * p / n)) * x - sin((2 * p / n)) * y);
        lb y1 = (sin(2 * p / n) * x + cos(2 * p / n) * y);
        // translating the vector back with cx, cy as origin
        x1 += cx;
        y1 += cy;
        cout << setprecision(10) << fixed << x1 << " " << y1 << endl;
    }
};

int main(){
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}
