#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}
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
ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1;
    x = x % p; // Update x if it is more than or equal to p
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

vector<int> primeFactorize(int x) {
    vector<int> res;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            res.push_back(i);
        }
    }
    if(x!=1){res.push_back(x);}
    return res;
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


int main() {
    // ifstream cin("../test_input.txt");
    fastInputOutput();

//    auto primes = LinearSieve::getPrimes(1000001);

//    int n; cin >> n;
//    for (int i = 0; i < n; i++) {
//        ll a; cin >> a;
//        ll prd = 1;
//        for (auto p: primes) {
//            if (p * p > a) break;
//            if (a % p != 0) continue;
//            ll cnt = 1;
//            while (a % p == 0) {
//                a /= p;
//                cnt++;
//            }
//            prd *= cnt;
//        }
//        if (a != 1) { // one prime remaining.
//            prd *= 2;
//        }
//        print(prd);
//    }

    return 0;
}