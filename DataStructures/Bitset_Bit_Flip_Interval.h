#include <bits/stdc++.h>
using namespace std;

#define ll long long


const ll N = 1e5 + 7;
class BitIntervalFlip {
public:
    bitset<N> bset;
    bitset<N> ones;
    BitIntervalFlip() {
        ones.flip();
    }
    void set(string &s) {
        bset = bitset<N>(s);
    }
    void flip(ll lo, ll hi) {
        if (lo > hi) swap(lo, hi);
        ll sz = hi - lo + 1;
        bitset<N> tmp = (ones << sz);
        tmp = ~tmp;
        tmp = (tmp << lo);
        bset = (bset ^ tmp);
    }
};


// TODO: implement the same with lazy segment tree (bcus it is several times faster)