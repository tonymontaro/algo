#include <bits/stdc++.h>
using namespace std;

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class FenwickTree {
    // One indexed Binary Indexed Tree.
    // (i & -i) => the least significant bit
public:
    int n;
    vector<ll> tree;
    FenwickTree(ll num){
        n = num;
        tree = vector<ll>(n + 1);
    }
    void update(ll index, ll value){
        for (ll i = index; i <= n; i += (i & -i))
            tree[i] += value;
    }
    ll query(ll index){
        ll total = 0;
        for (ll i = index; i > 0; i -= (i & -i))
            total += tree[i];
        return total;
    }
};


class FenwickTree2 {
    // One indexed FenwickTree (Binary Indexed Tree)
public:
    FenwickTree2(int nn) : n(nn), data(nn + 1) {}
    FenwickTree2(int nn, v<ll> dat) : n(nn), data(nn + 1) {
        assert(nn == dat.size());
        for (int i = 1; i < n + 1; i++) {
            data[i] += dat[i - 1];
            int parent = i + (i & -i);
            if (parent <= n)
                data[parent] += data[i];
        }
    }

    void add(int i, ll val) {
        // one indexed. E.g. [3,2], add(1, 2) -> [5, 2]
        assert(i > 0 && i <= n);
        while (i <= n) {
            data[i] += val;
            i += (i & -i);
        }
    }
    ll sum(int left, int right) {
        // inclusive sum from left to right. E.g. [2,3,5], sum(1, 3) -> 2 + 3 + 5 = 10.
        assert(left > 0 && left <= right && right <= n);
        return sum(right) - sum(left - 1);
    }
    ll sum(int i) {
        assert(i >= 0 && i <= n);
        ll ans = 0;
        while (i > 0) {
            ans += data[i];
            i -= (i & -i);
        }
        return ans;
    }

private:
    int n;
    vector<ll> data;
};






 