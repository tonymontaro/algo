#include <bits/stdc++.h>
using namespace std;

#define ll long long

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